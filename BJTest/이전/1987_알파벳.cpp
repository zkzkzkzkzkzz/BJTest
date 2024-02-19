#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<char> vecS;
int res = 0;

int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };

void solution(int row, int col, char board[][20], int startRow, int startCol, int passCnt)
{
	res = max(res, passCnt);

	for (int i = 0; i < 4; ++i)
	{
		int nx = startRow + dx[i];
		int ny = startCol + dy[i];

		if (nx < 0 || nx >= row || ny < 0 || ny >= col)
		{
			continue;
		}

		char c = board[nx][ny];
		vector<char>::iterator iter = vecS.begin();
		iter = find(vecS.begin(), vecS.end(), c);
		if (iter == vecS.end())
		{
			vecS.push_back(c);
			solution(row, col, board, nx, ny, passCnt + 1);
			iter = find(vecS.begin(), vecS.end(), c);
			if (iter != vecS.end())
			{
				vecS.erase(iter);
			}
		}
		
	}
}

int main()
{
	int R, C;
	cin >> R >> C;
	
	char board[20][20];

	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < C; ++j)
		{
			cin >> board[i][j];
		}
	}

	// 첫번째 칸 정보
	vecS.push_back(board[0][0]);
	solution(R, C, board, 0, 0, 1);

	cout << res << endl;

	return 0;
}
