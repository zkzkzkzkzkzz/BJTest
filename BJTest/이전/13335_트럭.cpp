#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


// 트럭 한 대가 다리를 지나가기 위해 필요한 시간은
// 다리의 길이(w)에 1을 더한 값
// 모든 트럭이 지나가야 하므로 구해야 하는 건
// 마지막 트럭이 다리에 처음 들어서는 시간
// 즉, 얼마만큼 시간이 지났을 때 마지막 트럭이 다리를 건너기 시작하는가
// 그 시간에 w를 더하면 구하고자 하는 최단 시간이 나온다


void solution(vector<int>& truck, int n, int w, int L)
{
	queue<int> q;
	int curWeight = 0;
	int time = 0;

	for (int i = 0; i < n; ++i)
	{
		int nextWeight = truck[i] + curWeight;

		while (true)
		{
			if (q.size() == w)
			{
				curWeight -= q.front();
				q.pop();
			}

			if (truck[i] + curWeight <= L)
			{
				break;
			}

			q.push(0);
			++time;
		}

		q.push(truck[i]);
		curWeight += truck[i];
		++time;
	}

	time += w;

	cout << time << endl;
}


int main()
{
	int n, w, L;
	cin >> n >> w >> L;

	vector<int> truck;

	for (int i = 0; i < n; ++i)
	{
		int a;
		cin >> a;
		truck.push_back(a);
	}

	solution(truck, n, w, L);

	return 0;
}