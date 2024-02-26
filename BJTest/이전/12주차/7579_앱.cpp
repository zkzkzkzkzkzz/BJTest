#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


// 앱은 각자 메모리를 사용하고 있고, 비활성화한 후 다시 실행하고자 할 경우 추가적으로 비용이 들어간다
// 비용이 0인 경우 무조건 끄는 것이 이득

int memory[101][2];	// memory[i][0] : i번째 앱의 메모리 크기, memory[i][1] : i번째 앱을 다시 실행하는데 드는 비용
int dp[10001];		// dp[i] : i만큼 비용을 썼을 때 확보할 수 있는 최대 메모리

void solution(int N, int M)
{
	if (M <= 0)
	{
		cout << 0 << endl;
		return;
	}

	int res = 0;

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 10000; j > 0; --j)
		{
			if (j >= memory[i][1])
			{
				// 비용이 0인 경우는 처음에 뺏기 때문에 고려하지 않는다
				if (0 == memory[i][1])
				{
					continue;
				}

				dp[j] = max(dp[j], dp[j - memory[i][1]] + memory[i][0]);
			}
		}
	}

	while (dp[res] < M)
	{
		++res;
	}

	cout << res << endl;
}


int main()
{
	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= N; ++i)
	{
		int memorysize;
		cin >> memorysize;
		memory[i][0] = memorysize;
	}

	for (int i = 1; i <= N; ++i)
	{
		int cost;
		cin >> cost;
		if (0 == cost)
		{
			M -= memory[i][0];
		}
		memory[i][1] = cost;
	}

	solution(N, M);

	return 0;
}