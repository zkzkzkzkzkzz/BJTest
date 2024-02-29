#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 만약 포도주가 두 잔이라면, dp[2]는 wine[1] + wine[2]다
// 세 잔부터는 마지막 잔을 마셨을 때, 안마셨을 때로 나뉘고
// 안마셨다면 최댓값은 이전꺼로 그대로 복사한다 (dp[i] = dp[i - 1])

// 만약 마셨다면 두가지 경우가 있다

// 1. 두번째, 세번째 잔을 마시는 경우
// - 첫번째 잔은 마실 수 없으므로 dp[3] = wine[2] + wine[3] + dp[0] 이 된다
// - dp[0]을 더하는 이유는 0번째 잔까지 마실 수 있는 최대 양에 첫번째 잔을 건너뛰고 두번째잔을 마시는 경우이기 때문

// 2. 두번째 잔을 마시지 않고 세번째 잔을 마시는 경우
// - 첫번째 잔까지 마실 수 있는 최대 양에 세번째 잔을 마시는 것이기 때문에
// - dp[3] = dp[1] + wine[3] 이 된다

// 즉, 위 세가지 경우에 대해 최댓값을 비교하면 된다


int wine[10001];
int dp[10001]; // dp[i] : i번째 잔까지 마셨을 경우 마실 수 있는 최대 포도주 양

void solution(int n)
{
	for (int i = 3; i <= n; ++i)
	{
		int a = dp[i - 3] + wine[i - 1] + wine[i];
		int b = dp[i - 2] + wine[i];

		dp[i] = max(dp[i - 1], max(dp[i - 3] + wine[i - 1] + wine[i], dp[i - 2] + wine[i]));
	}

	cout << dp[n] << endl;
}

int main()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i)
	{
		cin >> wine[i];
	}

	dp[0] = 0;
	dp[1] = wine[1];
	dp[2] = dp[1] + wine[2];

	solution(n);

	return 0;
}