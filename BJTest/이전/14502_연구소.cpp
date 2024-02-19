#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };


int countSafeArea(vector<vector<int>>& tempboard, int N, int M)
{
	int safeArea = 0;

	// 안전 영역 크기 계산
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (tempboard[i][j] == 0)
			{
				++safeArea;
			}
		}
	}

	return safeArea;
}



int infest(vector<vector<int>>& tempboard, int N, int M)
{	
	queue<pair<int, int>> q;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (tempboard[i][j] == 2)
			{
				q.push({ i,j });
			}
		}
	}

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M || tempboard[nx][ny] == 1 || tempboard[nx][ny] == 2)
			{
				continue;
			}

			tempboard[nx][ny] = 2;
			q.push({ nx, ny });
		}
	}

	int safecnt = 0;

	safecnt = countSafeArea(tempboard, N, M);

	return safecnt;
}


void solution(vector<vector<int>>& board)
{
	int res = 0;
	int N = (int)board.size();
	int M = (int)board[0].size();

	for (int i = 0; i < N * M; ++i)
	{
		for (int j = i + 1; j < N * M; ++j)
		{
			for (int k = j + 1; k < N * M; ++k)
			{
				// 벽 세개 선택
				int x1 = i / M, y1 = i % M;
				int x2 = j / M, y2 = j % M;
				int x3 = k / M, y3 = k % M;

				vector<vector<int>> tempboard = board;

				// 선택한 세곳이 모두 벽일때만 계산
				if (tempboard[x1][y1] == 0 && tempboard[x2][y2] == 0 && tempboard[x3][y3] == 0) 
				{
					tempboard[x1][y1] = tempboard[x2][y2] = tempboard[x3][y3] = 1;

					int safeCnt = infest(tempboard, N, M);
					res = max(res, safeCnt);
				}

			}
		}
	}

	cout << res << endl;
}

int main()
{
	int N, M;
	cin >> N >> M;

	vector<vector<int>> board(N, vector<int>(M));

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> board[i][j];
		}
	}

	solution(board);

	return 0;
}