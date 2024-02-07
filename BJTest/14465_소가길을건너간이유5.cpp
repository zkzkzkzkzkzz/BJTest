#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


void solution(int N, int K, vector<int>& crash)
{
	int res = 10000000;
	queue<int> q;
	int fix = 0;

	for (int i = 1; i < K + 1; ++i)
	{
		q.push(crash[i]);
		fix += crash[i];
		res = fix;
	}

	for (int i = K + 1; i < N + 1; ++i)
	{
		fix -= q.front();
		q.pop();
		q.push(crash[i]);
		fix += crash[i];

		res = min(res, fix);
	}

	cout << res << endl;
}


int main()
{
	int N, K, B;
	cin >> N >> K >> B;
	vector<int> crash(N + 1);

	for (int i = 0; i < B; ++i)
	{
		int A;
		cin >> A;
		crash[A] = 1;
	}

	solution(N, K, crash);

	return 0;
}