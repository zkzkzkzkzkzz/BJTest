#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int W[301];

int solution(int idx)
{
	if (idx == 0)
	{
		return W[0];
	}

	if (W[idx] != 0)
	{
		return W[idx];
	}

	return W[idx] = solution(idx - 1) + (idx * (idx + 1) * (idx + 2) / 2);
}

int main()
{
	int N;
	cin >> N;

	vector<int> sum;

	for (int i = 0; i < N; ++i)
	{
		int A;
		cin >> A;
		int res = solution(A);
		sum.push_back(res);
	}

	W[0] = 0;
	W[1] = 3;

	for (int i : sum)
	{
		cout << i << endl;
	}

	return 0;
}