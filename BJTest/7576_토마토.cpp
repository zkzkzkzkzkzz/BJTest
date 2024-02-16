#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

bool visit[1001][1001] = { false };

void solution(vector<vector<int>>& board, queue<pair<int,int>>& tomato)
{
	int N = board.size();
	int M = board[0].size();
	int cnt = -1;

	while (!tomato.empty())
	{
		int size = tomato.size();
		
		for (int i = 0; i < size; ++i)
		{
			int row = tomato.front().first;
			int col = tomato.front().second;
			tomato.pop();

			for (int i = 0; i < 4; ++i)
			{
				int nrow = row + dx[i];
				int ncol = col + dy[i];

				if (nrow < 0 || nrow >= N || ncol < 0 || ncol >= M || visit[nrow][ncol] || board[nrow][ncol] != 0)
				{
					continue;
				}

				board[nrow][ncol] = 1;
				visit[nrow][ncol] = true;
				tomato.push({ nrow, ncol });
			}
		}
		
		++cnt;
	}
	
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (board[i][j] == 0)
			{
				cout << -1 << endl;
				return;
			}
		}
	}

	cout << cnt << endl;
}


int main()
{
	int M, N;
	cin >> M >> N;

	vector<vector<int>> board(N, vector<int>(M));
	queue<pair<int, int>> tomato;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> board[i][j];

			if (board[i][j] == 1)
			{
				tomato.push({ i,j });
				visit[i][j] = true;
			}
		}
	}

	solution(board, tomato);

	return 0;
}