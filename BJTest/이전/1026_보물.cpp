#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, arrA[50], arrB[50];
vector<int> A;
vector<int> B;

// 기본 골자는 a의 최솟값과 b의 최댓값이 곱해여야 하는 것

void input()
{
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		cin >> arrA[i];
		A.push_back(arrA[i]);
	}

	for (int i = 0; i < N; ++i)
	{
		cin >> arrB[i];
		B.push_back(arrB[i]);
	}
}

int solution(vector<int> a, vector<int> b)
{
	priority_queue<int> pqA;
	priority_queue<int, vector<int>, greater<int>> pqB;

	for (size_t i = 0; i < a.size(); ++i)
	{
		pqA.push(a[i]);
		pqB.push(b[i]);
	}

	int res = 0;

	while (!pqA.empty())
	{
		res += pqA.top()* pqB.top();

		pqA.pop();
		pqB.pop();
	}
	
	return res;
}


int main()
{
	input();

	int res = solution(A, B);

	cout << res << endl;

	return 0;
}