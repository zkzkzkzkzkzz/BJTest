#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


// 모든 요청이 배정될 수 있으면 요청한 금액 그대로 배정
// 만약 배정될 수 없으면 특정한 정수 상한액을 계산하여 그 이상인 예산요청에는 상한액을 배정
// 상한액보다 낮은 금액은 그대로 배정

// left를 budget의 첫번째 인덱스(정렬했다는 가정하에)로 잡으면
// 5
// 100 100 100 100 100
// 10
// 이런 예시에서 0이 나와버림
// 즉, 항상 시작은 1부터 체크해야 한다 => left가 1부터 시작해야 함

bool ispossible(vector<int>& budget, int mid, int M)
{
	int res = 0;

	for (int i = 0; i < budget.size(); ++i)
	{
		if (budget[i] >= mid)
		{
			res += mid;
		}
		else
		{
			res += budget[i];
		}
	}

	return res <= M ? true : false;
}

void solution(vector<int>& budget, int M)
{
	sort(budget.begin(), budget.end());
	int res = 0;
	int N = budget.size();
	int left = 1;
	int right = budget[N - 1];

	while (left <= right)
	{
		int mid = left + (right - left) / 2;

		if (ispossible(budget, mid, M))
		{
			res = mid;
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}

	cout << res << endl;
}


int main()
{
	int N;
	cin >> N;

	vector<int> budget(N);

	for (int i = 0; i < N; ++i)
	{
		cin >> budget[i];
	}

	int M;
	cin >> M;

	solution(budget, M);

	return 0;
}