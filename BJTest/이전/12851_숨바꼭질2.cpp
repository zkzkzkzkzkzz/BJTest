#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int res[100001] = { 0 };    // 해당 좌표까지 가는 최소시간
int way[100001] = { 0 };    // 해당 좌표까지 최소시간으로 가는 경우의 수

void solution(int n, int k)
{
    queue<int> q;
    q.push(n);
    res[n] = 0;
    way[n] = 1;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        if (cur == k)
        {
            cout << res[cur] << endl;
            cout << way[cur] << endl;
            return;
        }

        for (int next : {cur - 1, cur + 1, cur * 2})
        {
            if (next >= 0 && next <= 100000)
            {
                // 방문하지 않은 위치라면
                if (res[next] == 0) 
                {
                    // next 좌표로 가는 시간은 cur 좌표에서 1초가 흐른 뒤
                    // -1, 1, *2 중 어떤 방법인지는 몰라도 세 가지 중 하나를 통해 next 좌표로 갔다
                    res[next] = res[cur] + 1;
                    way[next] = way[cur];
                    q.push(next);
                }

                // 이미 방문한 위치이고 최단 거리인 경우
                else if (res[next] == res[cur] + 1) 
                {
                    way[next] += way[cur];
                }
            }
        }
    }
}

int main()
{
    int N, K;
    cin >> N >> K;

    solution(N, K);

    return 0;
}
