#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16... 초기
// 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16... 1원 순회
// 0 1 2 3 4 1 2 3 4 5  2  3  4  5  6  3  4... 5원 순회하면서 최솟값 갱신
// 0 1 2 3 4 1 2 3 4 5  2  3  1  2  3  3  4... 12원 순회하면서 최솟값 갱신

int dp[10001];	// dp[i] : i원을 만들기 위한 최소 동전 개수

void solution(vector<int>& coins, int k)
{
	for (int i = 0; i < coins.size(); ++i)
	{
		// 정확하게 k원을 만드는 것이 목표이기 때문에 반복문을 k까지만 돌려도 된다
		for (int j = coins[i]; j <= k; ++j)
		{
			dp[j] = min(dp[j], dp[j - coins[i]] + 1);
		}
	}

	if (dp[k] == 100001)
	{
		cout << -1 << endl;
	}
	else
	{
		cout << dp[k] << endl;
	}
}

int main()
{
	int n, k;
	cin >> n >> k;
	
	vector<int> coins(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> coins[i];
	}

	for (int i = 1; i < 10001; ++i)
	{
		dp[i] = 100001;
	}

	solution(coins, k);

	return 0;
}