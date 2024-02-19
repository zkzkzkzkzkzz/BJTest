#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void solution(vector<pair<int, int>>& item, int K)
{
	int N = item.size();

	// dp[i][j] : 배낭에 i개만큼 넣고 무게가 j일때 최대 가치
	vector<vector<int>> dp(N + 1, vector<int>(K + 1, 0));

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= K; ++j)
		{
			// 현재 물건을 배낭에 넣을 수 있는 경우와 넣지 않는 경우 중 최댓값
			if (item[i - 1].first <= j)
			{
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - item[i - 1].first] + item[i - 1].second);
			}
			else
			{
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	cout << dp[N][K] << endl;
}


int main()
{
	int N, K;
	cin >> N >> K;

	int W, V;
	vector<pair<int, int>> item;
	for (int i = 0; i < N; ++i)
	{
		cin >> W >> V;
		item.push_back({ W,V });
	}

	solution(item, K);

	return 0;
}