#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


// 초기 풀이에선 1에서 시작한 게 아니라 다른 컴퓨터에서 시작해서 1번 컴퓨터로 도달하는 경우를 체크하지 못함

bool infested[101] = { false };

void solution(vector<vector<int>>& route, int start)
{
	queue<int> q;

	q.push(start);
	infested[start] = true;

	int cnt = 0;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (int next : route[cur])
		{
			if (!infested[next])
			{
				q.push(next);
				infested[next] = true;
				++cnt;
			}
		}
	}

	cout << cnt << endl;
}


int main()
{
	int N, M;

	cin >> N;
	cin >> M;

	vector<vector<int>> route(N+1);
	int A, B;
	for (int i = 0; i < M; ++i)
	{
		cin >> A >> B;
		route[A].push_back(B);
		route[B].push_back(A);
	}

	solution(route, 1);

	return 0;
}
