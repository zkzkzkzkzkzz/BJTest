#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

// 아래 예시에서
// 3
// 5 3
// 3 2
// 2 6

// dp[start][end]는 start에서 end까지의 행렬을 곱셈했을 때의 값이라고 하고,
// 분할정복 시 사용된 기준 값을 mid라고 할 때

// dp[1][3]은 mid가 1일때, mid가 2일때로 나눌 수 있고
// min(dp[1][1] + dp[2][3], dp[1][2] + dp[3][3]) + matrix[start].first * matrix[mid].second * matrix[end].first
// 로 나타낼 수 있다

int dp[501][501];	// dp[i][j] : i부터 j까지의 행렬을 곱했을 때의 최솟값

int solution(vector<pair<int, int>>& matrix, int start, int end)
{
	// 하나의 행렬은 곱할 수 없음
	if (start == end)
		return dp[start][end] = 0;

	// 이미 최솟값이 갱신된 경우
	if (dp[start][end] != INT_MAX)
	{
		return dp[start][end];
	}

	// 분할정복
	for (int mid = start; mid < end; ++mid)
	{
		int left = solution(matrix, start, mid);
		int right = solution(matrix, mid + 1, end);
		int temp = left + right + matrix[start].first * matrix[mid].second * matrix[end].second;
		dp[start][end] = min(dp[start][end], temp);
	}

	return dp[start][end];
}

int main()
{
	int N;
	cin >> N;
        
	vector<pair<int, int>> matrix(N + 1);

	for (int i = 1; i <= N; ++i)
	{
		// matrix[i].first : col, matrix[i].second : row
		cin >> matrix[i].first >> matrix[i].second;
	}

	for (int i = 0; i < 501; ++i)
	{
		for (int j = 0; j < 501; ++j)
		{
			dp[i][j] = INT_MAX;
		}
	}

	int res = solution(matrix, 1, N);

	cout << res << endl;

	return 0;
}