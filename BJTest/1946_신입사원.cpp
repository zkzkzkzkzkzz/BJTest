#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void solution(vector<vector<pair<int, int>>> test)
{
	int size = (int)test.size();

	for (int i = 0; i < size; ++i)
	{
		priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

		int cnt = 0;

		for (const auto j : test[i])
		{
			pq.push(j);
		}

		// 서류심사 1등의 면접 성적 순위
		int cutline = pq.top().second;
		++cnt;
		pq.pop();

		// pq에 남은 사람들은 면접 성적이 cutline보다는 작아야 한다
		while (!pq.empty())
		{
			// 만약 면접 성적 순위가 cutline보다 높다면(더 낮은 성적)
			if (pq.top().second > cutline)
			{
				pq.pop();
			}
			else
			{
				cutline = pq.top().second;	// cutline 갱신
				pq.pop();
				++cnt;
			}
		}

		cout << cnt << endl;
	}
}


int main()
{
	int T, N;

	cin >> T;

	vector<vector<pair<int, int>>> test;

	for (int i = 0; i < T; ++i)
	{
		cin >> N;
		int A, B;
		vector<pair<int, int>> score;

		for (int j = 0; j < N; ++j)
		{
			cin >> A >> B;

			score.push_back({ A, B });
		}

		test.push_back(score);
	}

	solution(test);

	return 0;
}