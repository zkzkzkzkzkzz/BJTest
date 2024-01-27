#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

// 영역구하기와 똑같이 

bool visit[101][101] = { false };
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };


// 일반
void bfs(vector<string> board, int x, int y, char color)
{
	int N = (int)board.size();

	queue<pair<int, int>> q;
	q.push({ x, y });
	visit[x][y] = true;
	
	while (!q.empty())
	{
		int x1 = q.front().first;
		int y1 = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nx = x1 + dx[i];
			int ny = y1 + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N || visit[nx][ny])
			{
				continue;
			}

			if (board[nx][ny] == color)
			{
				q.push({ nx, ny });
				visit[nx][ny] = true;
			}
		}
	}
}

// 적록색약
void bfs_RG(vector<string> board, int x, int y, char color)
{
	int N = (int)board.size();

	queue<pair<int, int>> q;
	q.push({ x, y });
	visit[x][y] = true;

	while (!q.empty())
	{
		int x1 = q.front().first;
		int y1 = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nx = x1 + dx[i];
			int ny = y1 + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N || visit[nx][ny])
			{
				continue;
			}

			// 현재 탐색해야 하는 색이 R 또는 G
			if (color == 'R' || color == 'G')
			{
				if (board[nx][ny] == 'R' || board[nx][ny] == 'G')
				{
					q.push({ nx, ny });
					visit[nx][ny] = true;
				}
			}

			// 탐색해야 하는 색이 G인 경우
			else
			{
				if (board[nx][ny] == color)
				{
					q.push({ nx, ny });
					visit[nx][ny] = true;
				}
			}
		}
	}
}


void solution(vector<string> board)
{
	int N = (int)board.size();

	int normal = 0;
	int unnormal = 0;

	// 일반사람
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (!visit[i][j])
			{
				bfs(board, i, j, board[i][j]);
				++normal;
			}
		}
	}

	// 방문 초기화
	for (int i = 0; i < 101; ++i)
	{
		for (int j = 0; j < 101; ++j)
		{
			visit[i][j] = false;
		}
	}

	// 적록색약
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (!visit[i][j])
			{
				bfs_RG(board, i, j, board[i][j]);
				++unnormal;
			}
		}
	}

	cout << normal << " " << unnormal << endl;
}


int main()
{
	int N;
	cin >> N;

	vector<string> board(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> board[i];
	}

	solution(board);

	return 0;
}