#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<pair<int, int>> vec)
{
    vector<int> dp(n + 1, 0);   // n일부터 (인덱스 + 1)일까지의 최대 수익을 담는 벡터

    for (int i = 0; i < vec.size(); ++i)
    {
        int duration = vec[n - i - 1].first;    // 해당 날짜 상담 소요 기간
        int price = vec[n - i - 1].second;      // 해당 상담 진행시 생기는 수익
        int Deadline = (n - i - 1) + duration;  // 해당 날짜 상담 진행 후 날짜 인덱스

        if (Deadline <= n)
        {
            // 해당 날짜의 상담을 진행할때의 수익과 진행하지 않았을 때의 수익 중 더 큰 값을 dp에 저장
            dp[n - i - 1] = max(dp[n - i], price + dp[Deadline]);
        }
        else
        {
            dp[n - i - 1] = dp[n - i];
        }
    }

    return dp[0];
}


int main()
{
	vector<pair<int, int>> vec = { {5,50},{4,40},{3,30},{2,20},{1,10},{1,10},{2,20}, {3,30}, {4,40}, {5,50} };

	int res = solution(10, vec);

	cout << res << endl;

	return 0;
}