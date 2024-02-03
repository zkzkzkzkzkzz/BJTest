#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
//
//// 한바퀴 돌았는데 과거로 돌아가기 위해선
//// 출발지점부터 도착지점까지 가는 비용(A)은 최소치로
//// 웜홀을 타고 다시 돌아오는 비용(B)은 최대치로 구했을 때
//// A - B가 음수가 나와야 한다
//
//
//// 벨먼-포드 알고리즘
//// 그래프에서 최단 경로 문제를 푸는 알고리즘
//// 다익스트라 알고리즘과 동일한 작업을 수행하나
//// 다익스트라 알고리즘은 가중치가 음수인 경우는 처리할 수 없다 -> 이때 벨먼-포드 알고리즘 사용
//// 실행속도는 다익스트라 알고리즘이 더 빠름
//
int INF = 987654321;

bool bellmanFord(vector<pair<pair<int, int>, int>>& edges, int n, int m, int w)
{
    // 각 노드까지의 최단 거리를 저장하는 벡터
    // 1부터 n까지의 노트를 나타내기 위해 n+1만큼 생성
    vector<int> dist(n + 1, INF);

    dist[1] = 0;    // 시작 노드의 최단 거리는 0

    // 벨만 포드 알고리즘은 정점의 개수를 n이라 하면 n-1번 반복한다
    // n-1번의 반복을 마치고도 거리가 갱신된다면 이는 음수 사이클이 존재한다는 의미

    // 최단거리 갱신
    for (int i = 0; i < n - 1; ++i) 
    {
        for (int j = 0; j < m + w; ++j) 
        {
            int start = edges[j].first.first;   // 시작 노드
            int end = edges[j].first.second;    // 도착 노드
            int time = edges[j].second;         // 비용

            if (dist[start] + time < dist[end])
            {
                dist[end] = dist[start] + time;
            }
        }
    }

    // 최단 거리를 갱신한 이후 음수 사이클이 있는지 확인
    for (int j = 0; j < m + w; ++j) 
    {
        int start = edges[j].first.first;
        int end = edges[j].first.second;
        int time = edges[j].second;

        if (dist[start] + time < dist[end])
        {
            return true;
        }
    }

    return false;
}

int main()
{
    int TC;
	cin >> TC;

    vector<string> res;

	while (TC > 0)
	{
		int n, m, w;
		
		cin >> n >> m >> w;

		vector<pair<pair<int, int>, int>> edges;

        for (int i = 0; i < m; ++i)
        {
            int s, e, t;
            cin >> s >> e >> t;
            edges.push_back({ {s, e}, t });
            edges.push_back({ {e, s}, t });
        }

        for (int i = 0; i < w; ++i)
        {
            int s, e, t;
            cin >> s >> e >> t;
            edges.push_back({ {s, e}, -t });
        }

        // 일반 도로는 양방향이므로 2배로 설정
		if (bellmanFord(edges, n, 2 * m, w))
		{
            res.push_back("YES");
		}
		else
		{
            res.push_back("NO");
		}

        --TC;
	}

    for (const auto s : res)
    {
        cout << s << endl;
    }

	return 0;
}