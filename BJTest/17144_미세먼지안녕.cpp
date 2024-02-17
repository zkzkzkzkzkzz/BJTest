#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

void spread(vector<vector<int>>& board, queue<pair<int, int>>& q)
{
	int N = board.size();
	int M = board[0].size();

	int size = q.size();

	for (int i = 0; i < size; ++i)
	{
		int r = q.front().first;
		int c = q.front().second;
		int amount = board[r][c] / 5;
		q.pop();
		
		for (int j = 0; j < 4; ++j)
		{
			int nr = r + dx[j];
			int nc = c + dy[j];

			if (nr < 0 || nr >= N || nc < 0 || nc >= M || board[nr][nc] == -1)
			{
				continue;
			}

			board[r][c] -= amount;
			board[nr][nc] += amount;

			q.push({ nr, nc });
		}
	}
}

void cleaner(vector<vector<int>>& board, vector<pair<int, int>>& cleanerpos)
{
	int N = board.size();
	int M = board[0].size();
	
	// 위쪽 공기청정기
	int upcleanerRow = cleanerpos[0].first;
	int upcleanerCol = cleanerpos[0].second;

	// 같은 열 먼지들 아래로 이동
	for (int i = 0; i < upcleanerRow; ++i)
	{
		if (upcleanerRow - 2 - i < 0)
		{
			continue;
		}

		board[upcleanerRow - 1 - i][0] = board[upcleanerRow - 2 - i][0];
	}

	// 첫번째행 먼지들 왼쪽으로 이동
	for (int i = 0; i < M; ++i)
	{
		if (i + 1 >= M)
		{
			continue;
		}

		board[0][i] = board[0][i + 1];
	}

	// 마지막열 먼지들 위쪽으로 이동
	for (int i = 0; i < M; ++i)
	{
		if (i + 1 >= upcleanerRow)
		{
			continue;
		}

		board[i][M - 1] = board[i + 1][M - 1];
	}

	// 위쪽 공기청정기와 같은 행의 먼지들 오른쪽으로 이동
	for (int i = 0; i < M - 1; ++i)
	{
		if (M - i - 2 <= 0)
		{
			board[upcleanerRow][M - 1 - i] = 0;
			continue;
		}

		board[upcleanerRow][M -1 - i] = board[upcleanerRow][M - i - 2];
	}

	int downcleanerRow = cleanerpos[1].first;
	int downcleanerCol = cleanerpos[1].second;

	// 첫번째열 먼지들 위쪽으로 이동
	for (int i = downcleanerRow; i < N; ++i)
	{
		if (i + 1 >= N)
		{
			continue;
		}

		board[i][0] = board[i + 1][0];
	}

	// 마지막행 먼지들 왼쪽으로 이동
	for (int i = 0; i < M; ++i)
	{
		if (i + 1 >= M)
		{
			continue;
		}

		board[N - 1][i] = board[N - 1][i + 1];
	}

	// 마지막열 먼지들 아래로 이동
	for (int i = 0; i < N - downcleanerRow; ++i)
	{
		if (N - 2 - i < downcleanerRow)
		{
			continue;
		}

		board[N - 1 - i][M - 1] = board[N - 2 - i][M - 1];
	}

	// 아래쪽 공기청정기와 같은 행의 먼지들 오른쪽으로 이동
	for (int i = 0; i < M - 1; ++i)
	{
		if (M - i - 2 <= 0)
		{
			board[downcleanerRow][M - 1 - i] = 0;
			continue;
		}

		board[downcleanerRow][M -1 - i] = board[downcleanerRow][M - i - 2];
	}
}

void solution(vector<vector<int>>& board, queue<pair<int, int>>& q, vector<pair<int, int>>& cleanerpos, int T)
{
	int N = board.size();
	int M = board[0].size();

	for (int i = 0; i < T; ++i)
	{
		spread(board, q);
		cleaner(board, cleanerpos);
	}

	int res = 0;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			res += board[i][j];
		}
	}

	cout << res << endl;
}

int main()
{
	int R, C, T;
	cin >> R >> C >> T;

	vector<vector<int>> board(R, vector<int>(C));
	queue<pair<int, int>> q;
	vector<pair<int, int>> cleanerpos;
	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < C; ++j)
		{
			cin >> board[i][j];

			if (board[i][j] == -1)
			{
				cleanerpos.push_back({ i,j });
			}
			else if (board[i][j] != 0)
			{
				q.push({i,j});
			}
		}
	}

	solution(board, q, cleanerpos, T);

	return 0;
}