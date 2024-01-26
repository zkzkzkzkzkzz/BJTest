#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int res[100001] = {0};			// 해당 좌표에 도달했을 때의 최솟값
bool visit[100001] = { false };	// 해당 좌표를 한번이라도 도착했었는가

// 수빈이가 선택할 수 있는 경우는 총 세가지
// 1. 왼쪽으로 한칸
// 2. 오른쪽으로 한칸
// 3. 현재위치에서 두배만큼의 좌표까지 순간이동

// 왼쪽으로만 갈 순 없으니까 0보다 작아지면 return
// 반대인 100000보다 커지는 경우도 동일

void solution(int n, int k)
{
	// 현재 좌표, 지나간 시간
	queue<pair<int, int>> q;

	q.push({ n, 0 });

	while (!q.empty())
	{
		int N = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (!visit[N] && (N >= 0 && N <= 100000))
		{
			visit[N] = true;

			if (res[N] == 0)
			{
				res[N] = cnt;
			}

			++cnt;

			q.push({ N - 1, cnt });
			q.push({ N + 1, cnt });
			q.push({ N * 2, cnt });
		}
	}

	cout << res[k] << endl;
}


int main()
{
	int N, K;

	cin >> N >> K;

	solution(N, K);

	return 0;
}