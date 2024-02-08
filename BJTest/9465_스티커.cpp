#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


int price[100001][2];

void dp(vector<vector<int>>& cost)
{
	int N = (int)cost.size();

	for (int i = 1; i <= N; ++i)
	{
		price[i][0] = max(price[i - 1][1] + cost[i - 1][0], price[i - 1][0]);
		price[i][1] = max(price[i - 1][0] + cost[i - 1][1], price[i - 1][1]);
	}

	cout << max(price[N][0], price[N][1]) << endl;
}

void solution(vector<vector<vector<int>>>& testcase)
{
	int T = (int)testcase.size();
	
	for (int i = 0; i < T; ++i)
	{
		vector<vector<int>> cost;
		int n = (int)testcase[i][0].size();

		for (int j = 0; j < n; ++j)
		{
			int cost1 = testcase[i][0][j];
			int cost2 = testcase[i][1][j];

			vector<int> temp;
			temp.push_back(cost1);
			temp.push_back(cost2);

			cost.push_back(temp);
		}

		dp(cost);
	}
}

int main()
{
	int T;
	cin >> T;
	vector<vector<vector<int>>> testcase;
	for (int i = 0; i < T; ++i)
	{
		int n;
		cin >> n;

		vector<vector<int>> sticker(2, vector<int>(n));

		for (int j = 0; j < n; ++j)
		{
			cin >> sticker[0][j];
		}

		for (int k = 0; k < n; ++k)
		{
			cin >> sticker[1][k];
		}

		testcase.push_back(sticker);
	}

	price[0][0] = 0;
	price[0][1] = 0;

	solution(testcase);

	return 0;
}