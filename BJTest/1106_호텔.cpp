#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


// 12명을 늘려야 하고 도시가 두개 있을 때(예시1)
// 1. 가장 마지막 홍보를 3원으로 했을 때
// 7명을 얻을 수 있는 최소 금액에 3원을 더한다
// 2. 가장 마지막 홍보를 1원으로 했을 때
// 11명을 얻을 수 있는 최소 금액에 1원을 더한다

//              12(0)
//              /  \
//             /    \
//           7(3)   11(1)
//           / \    /  \
//          /   \  /    \
//        2(6)  6(4)    10(2)

int ad[20][2];	// ad[0] : 각 도시를 홍보하는데 드는 비용, ad[1] : 얻을 수 있는 고객 수 
int dp[1001];	// dp[i] : i명을 확보하는데 드는 최소 비용

// 최소 C만큼 고객을 확보해야하고, 도시가 N만큼 있을 때 최소 비용
int solution(int C, int N)
{
	int res = 1000000;
	int cost = 0;

	if (C <= 0)
	{
		return 0;
	}
	else if (dp[C] > 0)
	{
		return dp[C];
	}
	else
	{
		for (int i = 0; i < N; ++i)
		{
			cost = solution(C - ad[i][1], N) + ad[i][0];
			res = min(res, cost);
		}

		dp[C] = res;

		return res;
	}
}


int main()
{
	int C, N;
	cin >> C >> N;

	for (int i = 0; i < N; ++i)
	{
		int cost, customer;
		cin >> cost >> customer;
		
		ad[i][0] = cost;
		ad[i][1] = customer;
	}

	int res = solution(C, N);

	cout << res << endl;

	return 0;
}