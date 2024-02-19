#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, ST[100000], ET[100000];
vector<pair<int, int>> times;

void input()
{
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		cin >> ST[i] >> ET[i];

		times.push_back({ ST[i], ET[i] });
	}
}


void solution(vector<pair<int, int>>& times)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	for (size_t i = 0; i < times.size(); ++i)
	{
		int end = times[i].second;
		int start = times[i].first;

		pq.push({ end, start });
	}

	int cnt = 0;

	while (!pq.empty())
	{
		int EndTime = pq.top().first;

		++cnt;

		pq.pop();

		while (!pq.empty() && pq.top().second < EndTime)
		{
			pq.pop();
		}
	}

	cout << cnt << endl;
}

int main()
{
	input();

	solution(times);

	return 0;
}