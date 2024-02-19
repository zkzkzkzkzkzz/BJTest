#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 높이가 2 이상 차이나면 해당 길은 지나갈 수 없음
// 높이가 모두 동일하면 지나갈 수 있음
// 높이가 1 차이날 때, 경사로 길이만큼의 영역이 필요함
// 경사로의 기울기는 일정해야한다
// 만약 경사로의 기울기가 반대가 될 때, 凹(요) 형태는 경사로 길이의 두배만큼 같은 높이의 영역이 필요하고
// 凸(철) 형태는 경사로 길이만큼 같은 높이의 영역이 필요하다
// 높이의 범위는 1 ~ 10

// 일단 길 하나를 벡터에 담고 인접한 두 칸의 높이 차이가 2이상이 나는지 확인 -> 하나라도 있다면 해당 길은 지나가는 것이 불가능
// 만약 올라가야 한다면 높이가 변한 인덱스에서 경사로 길이만큼 뒤로 돌아가야 하고
// 내려가야 한다면 높이가 변하기 직전 인덱스부터 경사로 길이만큼 앞으로 탐색해야 한다
// 경사로가 내려간 길은 visited check



bool checkroad(const vector<int>& road, int length)
{
	int size = (int)road.size();	// 해당 길의 길이

	// 경사로를 설치했는지 확인하는 벡터
	vector<bool> slope(size, false);

	// i == 현재 위치
	for (int i = 1; i < size; ++i)
	{
		int diff = road[i - 1] - road[i];

		// 높이차이가 1이면 경사로를 놓을 수 있는지 확인 -> 내려가는 경사로
		if (diff == 1)
		{
			// j == 경사로의 길이
			for (int j = 1; j <= length ; ++j)
			{
				// 현재 위치로부터 경사로의 길이가 road의 길이보다 길거나
				// 경사로가 설치된 칸의 높이가 현재 칸의 높이와 다르거나
				// 경사로를 설치하려는데 이미 그 칸에 경사로가 설치되었다면
				if (i + j - 1 >= size || road[i] != road[i + j - 1] || slope[i + j - 1])
				{
					return false;
				}

				slope[i + j - 1] = true;
			}
		}

		// 높이차이가 -1이면 경사로를 놓을 수 있는지 확인 -> 올라가는 경사로
		else if (diff == -1)
		{
			for (int j = 0; j < length; ++j)
			{
				// 현재 위치에서 j만큼 이동했을 때 길을 벗어나거나
				// 경사로가 설치된 칸의 높이가 현재 칸의 높이와 다르거나
				// 경사로를 설치하려는데 이미 그 칸에 경사로가 설치되었다면
				if (i - j - 1 < 0 || road[i - 1] != road[i - j - 1] || slope[i - j - 1])
				{
					return false;
				}

				slope[i - j - 1] = true;
			}
		}

		// 높이차이가 2 이상이면
		else if (abs(diff) > 1)
		{
			return false;
		}
	}

	return true;
}

int solution(int n, int length, vector<vector<int>> road)
{
	int cnt = 0;

	// 가로 방향으로 길 검사
	for (int i = 0; i < n; ++i)
	{
		// 해당 길을 지나갈 수 있다면
		if (checkroad(road[i], length))
		{
			++cnt;
		}
	}

	// 세로 방향으로 길 검사
	for (int i = 0; i < n; ++i)
	{
		vector<int> colroad;

		for (int j = 0; j < n; ++j)
		{
			colroad.push_back(road[j][i]);
		}

		if (checkroad(colroad, length))
		{
			++cnt;
		}
	}

	return cnt;
}

int main()
{
	int N, L;
	cin >> N >> L;

	vector<vector<int>> road(N, vector<int>(N));

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> road[i][j];
		}
	}

	int res = solution(N, L, road);

	cout << res << endl;

	return 0;
}