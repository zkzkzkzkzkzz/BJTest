#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;



int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
bool visit[1001][1001][2];		// visit[i][j][0] : 벽을 안부순 상태로 (i,j)에 도달, visit[i][j][1] : 벽을 부순 상태에서 (i,j)에 도달


int solution(int N, int M, vector<string>& board)
{
	//              row, col    breakwall, dist
	queue<pair<pair<int, int>, pair<int, int>>> q;

	// 초기 좌표는 (0,0)에 벽을 부수지 않은 상태에서 거리 1의 값을 가짐
	q.push({ {0, 0}, {0, 1} });

	while (!q.empty())
	{
		int row = q.front().first.first;
		int col = q.front().first.second;
		int wall = q.front().second.first;
		int dist = q.front().second.second;
		q.pop();

		if (row == N && col == M)
			return dist;

		for (int i = 0; i < 4; ++i)
		{
			int nrow = row + dx[i];
			int ncol = col + dy[i];

			if (nrow < 0 || nrow > N || ncol < 0 || ncol > M || visit[nrow][ncol][wall])
			{
				continue;
			}

			// 벽을 부순 적이 없고, 해당 좌표가 벽이 없을 때
			if (wall == 0 && board[nrow][ncol] == '0')
			{
				visit[nrow][ncol][wall] = true;
				q.push({ {nrow, ncol}, {0, dist + 1} });
			}
			// 벽을 부순 적이 없고, 해당 좌표에 벽이 있을 때
			else if (wall == 0 && board[nrow][ncol] == '1')
			{
				visit[nrow][ncol][wall] = true;
				q.push({ {nrow, ncol}, {1, dist + 1} });
			}
			// 벽을 부순 적이 있고, 해당 좌표에 벽이 없을 때
			else if (wall == 1 && board[nrow][ncol] == '0')
			{
				visit[nrow][ncol][wall] = true;
				q.push({ {nrow, ncol}, {1, dist + 1} });
			}
			// 벽을 부순 적이 있고, 해당 좌표에 벽이 있을 때는 이동불가
		}
	}

	return -1;
}


int main()
{
	int N, M;
	cin >> N >> M;

	vector<string> board(N);

	for (int i = 0; i < N; ++i)
	{
		cin >> board[i];
	}

	visit[0][0][0] = true;
	visit[0][0][1] = true;

	int res = solution(N - 1, M - 1, board);

	cout << res << endl;

	return 0;
}