#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<vector<int>> city;
vector<pair<int, int>> chickens;	// 치킨집 위치
vector<pair<int, int>> houses;		// 집 위치

void input()
{
	cin >> N >> M;

	city.resize(N, vector<int>(N));

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> city[i][j];

			if (city[i][j] == 1)
			{
				houses.push_back({ i, j });
			}
			else if (city[i][j] == 2)
			{
				chickens.push_back({ i,j });
			}
		}
	}
}

int ChickenDistance(vector<int> CurChicken)
{
	int Sum = 0;

	for (const auto& house : houses)
	{
		int minDist = 100000000;

		for (const auto& index : CurChicken)
		{
			int X = chickens[index].first;
			int Y = chickens[index].second;
			int dist = abs(house.first - X) + abs(house.second - Y);
			minDist = min(minDist, dist);
		}

		Sum += minDist;
	}

	return Sum;
}

void solution()
{
	vector<int> IsChickenAlive;	// 현재 치킨집이 살아있는가

	for (int i = 0; i < M; ++i)
	{
		IsChickenAlive.push_back(1); // 살아있음
	}

	for (int i = 0; i < (int)chickens.size() - M; ++i)
	{
		IsChickenAlive.push_back(0);	// 폐업
	}

	// next_permutation 함수를 사용하기 전에 범위에 속한 원소들이 오름차순으로 정렬되어 있어야 한다
	sort(IsChickenAlive.begin(), IsChickenAlive.end());

	int res = 10000000;

	do
	{
		vector<int> CurChicken;

		for (int i = 0; i < (int)IsChickenAlive.size(); ++i)
		{
			if (IsChickenAlive[i] == 1)
			{
				CurChicken.push_back(i);
			}
		}

		int Dist = ChickenDistance(CurChicken);

		res = min(res, Dist);

	} while (next_permutation(IsChickenAlive.begin(), IsChickenAlive.end()));

	cout << res << endl;
}

int main()
{
	input();
	solution();

	return 0;
}