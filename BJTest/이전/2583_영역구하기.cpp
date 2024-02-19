#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


// 좌표를 모눈종이화 시킨다면
// 우상단 좌표는 각각 -1을 해야 모눈종이에 맞는 인덱스가 생긴다
// 비어있는 곳을 0, 사각형이 채워져있는 곳을 1로 바꿔서 보드를 새로 만들면
// 0이 있는 곳의 영역의 넓이를 구하면 된다

bool visit[101][101] = { false };
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

int bfs(vector<vector<int>> board, int x, int y)
{
	int M = (int)board.size();
	int N = (int)board[0].size();

	queue<pair<int, int>> q;

	// 초기값 설정
	q.push({ x, y });
	visit[x][y] = true;
	int area = 1;

	while (!q.empty())
	{
		int x1 = q.front().first;
		int y1 = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nx = x1 + dx[i];
			int ny = y1 + dy[i];

			if (nx < 0 || nx >= M || ny < 0 || ny >= N || board[nx][ny] == 1 || visit[nx][ny])
			{
				continue;
			}

			q.push({ nx, ny });
			visit[nx][ny] = true;
			++area;
		}
	}

	return area;
}



void solution(vector<vector<int>> board)
{
	int M = (int)board.size();
	int N = (int)board[0].size();
	
	vector<int> area;

	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			// 해당 영역이 비어있고, 방문한 적이 없으면
			if (board[i][j] == 0 && !visit[i][j])
			{
				int res = bfs(board, i, j);
				area.push_back(res);
			}
		}
	}

	sort(area.begin(), area.end());

	int size = (int)area.size();

	cout << size << endl;

	for (int i : area)
	{
		cout << i << " ";
	}
}


int main()
{
	int M, N, K;

	cin >> M >> N >> K;

	int x1, y1, x2, y2;

	vector<vector<int>> board(M, vector<int>(N, 0));
	

	for (int i = 0; i < K; ++i)
	{
		cin >> x1 >> y1 >> x2 >> y2;

		for (int j = y1; j < y2; ++j)
		{
			for (int k = x1; k < x2; ++k)
			{
				board[j][k] = 1;
			}
		}
	}

	solution(board);

	return 0;
}