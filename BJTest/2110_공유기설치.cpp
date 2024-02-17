#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool canwifi(int mid, vector<int>& house, int C)
{
	int cnt = 1;			// 현재까지 설치된 공유기의 개수
	int last = house[0];	// 현재까지 설치한 집 중 가장 오른쪽에 있는 집의 좌표

	for (int i = 1; i < house.size(); ++i)
	{
		if (house[i] - last >= mid)
		{
			++cnt;
			last = house[i];
		}
	}

	return cnt >= C;
}

void solution(vector<int>& house, int C)
{
	sort(house.begin(), house.end());

	int res = 0;

	int N = house.size();
	int left = 1;
	int right = house[N - 1] - house[0];

	while (left <= right)
	{
		int mid = left + (right - left) / 2;

		if (canwifi(mid, house, C))
		{
			res = mid;
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}

	cout << res << endl;
}

int main()
{
	int N, C;
	cin >> N >> C;

	vector<int> house(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> house[i];
	}

	solution(house, C);

	return 0;
}