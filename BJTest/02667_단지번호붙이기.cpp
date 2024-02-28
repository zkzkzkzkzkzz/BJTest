#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
bool visit[26][26] = { false };

int CheckArea(vector<vector<int>>& board, int row, int col)
{
	int Row = board.size();
	int Col = board[0].size();
	int area = 1;

	queue<pair<int, int>> q;
	q.push({ row, col });

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= Row || ny < 0 || ny >= Col || visit[nx][ny] || board[nx][ny] == 0)
			{
				continue;
			}

			visit[nx][ny] = true;
			q.push({ nx, ny });
			++area;
		}
	}

	return area;
}

void solution(vector<string>& board)
{
	int row = board.size();
	int col = board[0].size();

	vector<vector<int>> area(row, vector<int>(col));

	for (int i = 0; i < board.size(); ++i)
	{
		for (int j = 0; j < board.size(); ++j)
		{
			if (board[i][j] == '0')
			{
				area[i][j] = 0;
			}
			else
			{
				area[i][j] = 1;
			}
		}
	}

	vector<int> res;

	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			if (1 == area[i][j] && !visit[i][j])
			{
				visit[i][j] = true;
				int temp = CheckArea(area, i, j);
				res.push_back(temp);
			}
		}
	}

	sort(res.begin(), res.end());
	int size = res.size();
	cout << size << endl;

	for (int i : res)
	{
		cout << i << endl;
	}
}

int main()
{
	int N;
	cin >> N;

	vector<string> board;

	for (int i = 0; i < N; ++i)
	{
		string s;
		cin >> s;
		board.push_back(s);
	}

	solution(board);

	return 0;
}