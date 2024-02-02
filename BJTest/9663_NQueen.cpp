#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


// 퀸은 같은 행, 같은 열에 두 개 이상 존재할 수 없음
// + 해당 좌표에서 대각선까지 체크

int res = 0;

bool isSafe(vector<int>& board, int row, int col) 
{
    // 같은 열 + 대각선에 다른 퀸이 있는지 확인
    for (int i = 0; i < row; ++i) 
    {
        if (board[i] == col || abs(board[i] - col) == abs(i - row)) 
        {
            return false;
        }
    }
    return true;
}

void solution(vector<int>& board, int row)
{
    int N = (int)board.size();

    if (row == N)
    {
        // 모든 행에 퀸을 놓은 경우
        ++res;
        return;
    }

    for (int col = 0; col < N; ++col) 
    {
        if (isSafe(board, row, col)) 
        {
            board[row] = col;
            solution(board, row + 1);
            board[row] = -1;    // 해당 위치에 둔 퀸 회수
        }
    }
}


int main()
{
	int N;
	cin >> N;

    vector<int> board(N, -1);

    solution(board, 0);

    cout << res << endl;

    return 0;
}