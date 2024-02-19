#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// → 일때는 →, ↘ 두 가지 방법으로 이동할 수 있고,
// ↘ 일때는 →, ↘, ↓ 세 가지 방법으로 이동할 수 있고,
// ↓ 일때는 ↘, ↓ 두 가지 방법으로 이동할 수 있다

// 파이프는 머리와 꼬리로 이루어져 있다고 하면
// 머리의 좌표에서 꼬리의 좌표까지 사각형 범위를 가진다
// 근데 머리가 갈 수 있는 곳은 꼬리도 당연히 갈 수 있기 때문에 머리 좌표만 신경써도 될 듯

int N, ans = 0;
int board[17][17];
bool visit[17][17] = { false };
int dx[3] = { 0, 1, 1 };
int dy[3] = { 1, 0, 1 };

void solution(int x, int y, int dir) 
{
	if (x == N - 1 && y == N - 1)
	{
		++ans;
		return;
	}

	visit[x][y] = true;

	for (int i = 0; i < 3; i++) 
	{
		// 파이프 가로 && 세로 방향으로 이동
		if (dir == 0 && i == 1)
		{
			continue; 
		}
		// 파이프 세로 && 가로 방향으로 이동
		else if (dir == 1 && i == 0)
		{
			continue;
		}
		else 
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N)
			{
				continue;
			}

			if (i < 2) 
			{ 
				// 가로, 세로로 이동
				if (board[nx][ny] == 0 && !visit[nx][ny]) 
				{
					solution(nx, ny, i);
					visit[nx][ny] = false;
				}
			}
			else 
			{ 
				//대각선
				if (board[nx][ny] == 0 && board[nx - 1][ny] == 0 && board[nx][ny - 1] == 0 && !visit[nx][ny])
				{
					solution(nx, ny, i);
					visit[nx][ny] = false;
				}
			}
		}
	}
}

int main() 
{
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> board[i][j];
		}
	}

	solution(0, 1, 0);

	cout << ans << endl;

	return 0;
}
