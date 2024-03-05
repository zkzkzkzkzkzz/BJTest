#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dp[501][501];	// dp[i][j] : 판다를 (i, j)에 풀어놓을 때 최대 이동할 수 있는 칸의 수

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
int res = 0;

void solution(vector<vector<int>>& board, int row, int col)
{
	if (dp[row][col] != 0)
	{
		return;
	}

	int size = board.size();
	int maxtree = 0;

	for (int i = 0; i < 4; ++i)
	{
		int nrow = row + dx[i];
		int ncol = col + dy[i];

		if (nrow < 0 || nrow >= size || ncol < 0 || ncol >= size || board[row][col] >= board[nrow][ncol])
		{
			continue;
		}

		solution(board, nrow, ncol);

		maxtree = max(maxtree, dp[nrow][ncol]);
	}

	dp[row][col] = maxtree + 1;


	res = max(res, dp[row][col]);
}

int main()
{
	int n;
	cin >> n;
	int maxtree = 0;
	int x, y;
	vector<vector<int>> board(n, vector<int>(n));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			solution(board, i, j);
		}
	}


	cout << res << endl;

	return 0;
}