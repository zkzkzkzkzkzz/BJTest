#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14
// 0 0 0 1 0 0 2 0 0 3  0  0  4  0  0  : 3킬로 배달했을 때
// 0 0 0 1 0 1 2 0 2 3  2  3  4  3  0  : 5킬로 배달했을 때

// 가능한 경우 N이 3의 배수일 때, 5의 배수일 때, 5로 나눈 나머지가 3의 배수일 때
int dp[5001]; // dp[i] : 설탕 i킬로그램을 배달할 때 필요한 최소 봉지 개수

void solution(int N)
{
	// 5의 배수라면 무조건 5로만 채우는 게 제일 적게 봉지를 쓸 수 있다
	if (N % 5 == 0)
	{
		cout << N / 5 << endl;
		return;
	}

	for (int i = 5; i <= N; ++i)
	{
		if (dp[i - 3] != 10000 || dp[i-5] != 10000)
		{
			dp[i] = min(dp[i - 3] + 1, dp[i - 5] + 1);
		}
	}

	if (dp[N] != 10000)
	{
		cout << dp[N] << endl;
	}
	else
	{
		cout << -1 << endl;
	}

	return;
}


int main()
{
	int N;
	cin >> N;

	for (int i = 1; i < 5001; ++i)
	{
		dp[i] = 10000;
	}
	dp[0] = 0;
	dp[3] = 1;
	dp[5] = 1;

	solution(N);

	return 0;
}