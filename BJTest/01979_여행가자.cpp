#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Union Find 알고리즘
// 서로 중복되지 않는 부분 집합들로 나눠진 원소들에 대한 정보를 저장하고 조작하는 자료구조인
// 'Disjoint Set'을 표현할 때 사용하는 알고리즘

// make-set(x)	: x를 유일한 원소로 하는 새로운 집합을 만든다
// union(x, y)	: x가 속한 집합과 y가 속한 집합을 합친다
// find(x)		: x가 속한 집합의 루트 노드를 반환한다

int p[201];

int find(int x)
{
	if (p[x] == x)
		return x;

	return p[x] = find(p[x]);
}

void union_node(int x, int y)
{
	x = find(x);
	y = find(y);

	if (x < y)
		p[y] = x;
	else
		p[x] = y;
}

int main()
{
	int N, M;
	cin >> N >> M;

	// make-set(x)
	for (int i = 1; i <= N; ++i)
	{
		p[i] = i;
	}

	// union(x, y)
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			int a;
			cin >> a;

			if (a == 1)
			{
				union_node(i, j);
			}
		}
	}

	// find(x)
	int root;
	for (int i = 0; i < M; ++i)
	{
		int a;
		cin >> a;

		if (i == 0)
		{
			root = find(a);
		}
		else
		{
			if (find(root) != find(a))
			{
				cout << "NO" << endl;
				return 0;
			}
		}
	}

	cout << "YES" << endl;
	return 0;
}