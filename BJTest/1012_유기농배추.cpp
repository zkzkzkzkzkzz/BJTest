#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

bool visit[51][51] = { false };

void bfs(vector<vector<int>>& board, int x, int y)
{
    int row = (int)board.size();
    int col = (int)board[0].size();

    queue<pair<int, int>> q;
    q.push({ x, y });
    board[x][y] = 0;

    while (!q.empty())
    {
        int x1 = q.front().first;
        int y1 = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            int nx = x1 + dx[i];
            int ny = y1 + dy[i];

            if (nx < 0 || nx >= row || ny < 0 || ny >= col || board[nx][ny] == 0 || visit[nx][ny])
            {
                continue;
            }

            q.push({ nx, ny });
            visit[nx][ny] = true;
        }
    }
}

int solution(vector<vector<int>>& board)
{
    int row = (int)board.size();
    int col = (int)board[0].size();
    int cnt = 0;

    for (int i = 0; i < 51; ++i)
    {
        for (int j = 0; j < 51; ++j)
        {
            visit[i][j] = false;
        }
    }

    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            if (board[i][j] == 1 && !visit[i][j])
            {
                bfs(board, i, j);
                ++cnt;
            }
        }
    }

    return cnt;
}

int main()
{
    int T;
    cin >> T;
    vector<int> res;
    for (int i = 0; i < T; ++i)
    {
        int M, N, K;
        cin >> M >> N >> K;

        vector<vector<int>> board(N, vector<int>(M, 0));

        for (int j = 0; j < K; ++j)
        {
            int x, y;
            cin >> x >> y;
            board[y][x] = 1;
        }

        res.push_back(solution(board));
    }

    for (auto i : res)
    {
        cout << i << endl;
    }

    return 0;
}
