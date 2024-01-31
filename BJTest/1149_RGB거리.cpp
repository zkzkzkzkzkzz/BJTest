#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int house[1001][3];

void solution(vector<vector<int>>& cost)
{
	int N = (int)cost.size();
	
	for (int i = 1; i <= N; ++i)
	{
		// 집을 빨간색으로 칠할 때
		// 이전 집이 초록색 또는 파란색으로 칠해져야 하고, 이번에 빨간색으로 칠한다
		// house는 집번호를 따라 1번부터 시작했지만, cost의 경우 벡터에 push_back한 것이기 때문에
		// i번째 집을 칠하는 비용은 (i - 1)번 인덱스가 된다
		house[i][0] = min(house[i - 1][1], house[i - 1][2]) + cost[i - 1][0];

		// 집을 초록색으로 칠할 때
		house[i][1] = min(house[i - 1][0], house[i - 1][2]) + cost[i - 1][1];

		// 집을 파란색으로 칠할 때
		house[i][2] = min(house[i - 1][0], house[i - 1][1]) + cost[i - 1][2];
	}


	cout << min(house[N][2], min(house[N][0], house[N][1])) << endl;
}



int main()
{
	int N;

	cin >> N;

	vector<vector<int>> cost;
	int R, G, B;

	for (int i = 0; i < N; ++i)
	{
		cin >> R >> G >> B;

		cost.push_back({R, G, B});
	}

	house[0][0] = 0;
	house[0][1] = 0;
	house[0][2] = 0;

	solution(cost);

	return 0;
}