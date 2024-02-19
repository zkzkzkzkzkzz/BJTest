#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<pair<int, int>> vec)
{
    vector<int> dp(n + 1, 0);   // n�Ϻ��� (�ε��� + 1)�ϱ����� �ִ� ������ ��� ����

    for (int i = 0; i < vec.size(); ++i)
    {
        int duration = vec[n - i - 1].first;    // �ش� ��¥ ��� �ҿ� �Ⱓ
        int price = vec[n - i - 1].second;      // �ش� ��� ����� ����� ����
        int Deadline = (n - i - 1) + duration;  // �ش� ��¥ ��� ���� �� ��¥ �ε���

        if (Deadline <= n)
        {
            // �ش� ��¥�� ����� �����Ҷ��� ���Ͱ� �������� �ʾ��� ���� ���� �� �� ū ���� dp�� ����
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