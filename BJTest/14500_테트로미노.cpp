#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// 각 모양별로 만들 수 있는 값들 중 최댓값끼리 비교해서 최종적인 최댓값을 구한다

vector<vector<pair<int, int>>> tetromino =
{
    {{0, 0}, {0, 1}, {0, 2}, {0, 3}},
    {{0, 0}, {1, 0}, {2, 0}, {3, 0}},
    {{0, 0}, {0, 1}, {1, 0}, {1, 1}},
    {{0, 0}, {0, 1}, {0, 2}, {-1, 2}},
    {{0, 0}, {0, 1}, {1, 1}, {2, 1}},
    {{0, 0}, {0, 1}, {0, 2}, {1, 0}},
    {{0, 0}, {1, 0}, {2, 0}, {2, 1}},
    {{0, 0}, {1, 0}, {1, 1}, {1, 2}},
    {{0, 0}, {0, 1}, {-1, 1}, {-2, 1}},
    {{0, 0}, {0, 1}, {0, 2}, {1, 2}},
    {{0, 0}, {0, 1}, {1, 0}, {2, 0}},
    {{0, 0}, {0, 1}, {0, 2}, {-1, 1}},
    {{0, 0}, {0, 1}, {-1, 1}, {1, 1}},
    {{0, 0}, {0, 1}, {0, 2}, {1, 1}},
    {{0, 0}, {-1, 0}, {1, 0}, {0, 1}},
    {{0, 0}, {0, 1}, {1, 1}, {1, 2}},
    {{0, 0}, {0, 1}, {-1, 1}, {1, 0}},
    {{0, 0}, {0, 1}, {-1, 1}, {-1, 2}},
    {{0, 0}, {-1, 0}, {0, 1}, {1, 1}}
};


bool isValid(int r, int c,vector<pair<int, int>>& shape, int N, int M)
{
    for (auto i : shape)
    {
        int nr = r + i.first;
        int nc = c + i.second;

        if (nr < 0 || nr >= N || nc < 0 || nc >= M)
        {
            return false;
        }
    }
  
    return true;
}

int shapeSum(int r, int c, vector<pair<int, int>>& shape, vector<vector<int>>& board)
{
    int res = 0;

    for (auto i : shape)
    {
        int nr = r + i.first;
        int nc = c + i.second;

        res += board[nr][nc];
    }

    return res;
}

void solution(vector<vector<int>>& board)
{
    int N = board.size();
    int M = board[0].size();

    int res = 0;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            for (auto shape : tetromino)
            {
                if (isValid(i, j, shape, N, M))
                {
                    int sum = shapeSum(i, j, shape, board);
                    res = max(res, sum);
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