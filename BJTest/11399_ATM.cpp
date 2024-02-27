#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;




void solution(vector<int>& P)
{
	sort(P.begin(), P.end());

	int cur = 0, prev = 0, res = 0;

	res = cur = prev = P[0];

	for (int i = 1; i < P.size(); ++i)
	{
		cur = prev + P[i];

		res += cur;

		prev = cur;
	}

	cout << res << endl;
}


int main()
{
	int N;
	cin >> N;

	vector<int> P(N);

	for (int i = 0; i < N; ++i)
	{
		cin >> P[i];
	}

	solution(P);

	return 0;
}