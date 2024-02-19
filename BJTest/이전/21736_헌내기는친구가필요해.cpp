#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

bool visit[601][601] = { false };
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

//OOOPO
//OIOOX
//OOOXP
void solution(char board[][601], int x, int y, int N, int M)
{
	queue<pair<int, int>> q;
	q.push({ x,y });

	int cnt = 0;

	while (!q.empty())
	{
		int x1 = q.front().first;
		int y1 = q.front().second;
		q.pop();


		for (int i = 0; i < 4; ++i)
		{
			int nx = x1 + dx[i];
			int ny = y1 + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M || visit[nx][ny] || board[nx][ny] == 'X')
			{
				continue;
			}

			if (board[nx][ny] == 'P')
			{
				++cnt;
			}

			visit[nx][ny] = true;
			q.push({ nx, ny });
		}
	}

	if (cnt == 0)
	{
		cout << "TT" << endl;

		return;
	}

	cout << cnt << endl;
}



int main()
{
	int N, M;

	cin >> N >> M;

	int startx = 0;
	int starty = 0;

	char board[601][601];
	char c = {};

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> c;

			board[i][j] = c;

			if (c == 'I')
			{
				startx = i;
				starty = j;
				visit[i][j] = true;
				board[i][j] = 'O';
			}
		}
	}

	solution(board, startx, starty, N, M);

	return 0;
}