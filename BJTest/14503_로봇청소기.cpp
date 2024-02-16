#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
       
//             북,  동, 남,  서
int dx[4] = { -1,   0,  1,  0 };
int dy[4] = { 0,    1,  0,  -1 };

void turnleft(int& d)
{
    d = (d + 3) % 4;
}

bool moveback(vector<vector<int>>& board, int& r, int& c, int& d)
{
    int nr = r - dx[d];
    int nc = c - dy[d];

    if (board[nr][nc] != 1)
    {
        r = nr;
        c = nc;
        return true;
    }

    return false;
}


void solution(vector<vector<int>>& board, int r, int c, int d)
{
    int N = (int)board.size();
    int M = (int)board[0].size();
    int cnt = 0;

    while (true)
    {
        // 1. 해당 칸이 청소가 안되어있다면
        if (board[r][c] == 0)
        {
            board[r][c] = 2;
            ++cnt;
        }

        bool moved = false;

        // 주변 4칸의 청소 필요 여부 확인
        for (int i = 0; i < 4; ++i)
        {
            // 반시계 회전
            turnleft(d);

            int nr = r + dx[d];
            int nc = c + dy[d];

            if (board[nr][nc] == 0)
            {
                r = nr;
                c = nc;
                moved = true;
                break;
            }
        }

        // 주변 4칸이 청소할 필요가 없는 경우 후진
        if (!moved)
        {
            // 후진이 불가능하다 == 벽에 도달했다
            if (!moveback(board, r, c, d))
            {
                break;
            }
        }
    }

    cout << cnt << endl;
}

int main()
{
    int N, M;
    cin >> N >> M;

    int r, c, d;
    cin >> r >> c >> d;

    vector<vector<int>> board(N, vector<int>(M));

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> board[i][j];
        }
    }

    solution(board, r, c, d);

    return 0;
}