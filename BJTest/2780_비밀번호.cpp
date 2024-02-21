#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// 비밀번호는 인접한 숫자로만 이어질 수 있다
// 만약 1부터 시작한다면 다음으로 올 수 있는 번호는 1, 4
// 2부터 시작한다면 다음으로 올 수 있는 번호는 1, 3, 5이다
// 반대로 얘기하면 번호 1을 누를 수 있는 경우는 이전 비밀번호가 2 또는 4일 때 뿐이다


long long password[1001][10] = {};

void solution(long long T, vector<long long>& testcase)
{
	for (long long i = 2; i <= 1000; ++i)
	{
		for (long long j = 0; j < 10; ++j)
		{
			switch (j)
			{
			case 0:
				password[i][j] = password[i - 1][7] % 1234567;
				break;
			case 1:
				password[i][j] = (password[i - 1][2] + password[i - 1][4]) % 1234567;
				break;
			case 2:
				password[i][j] = (password[i - 1][1] + password[i - 1][3] + password[i - 1][5]) % 1234567;
				break;
			case 3:
				password[i][j] = (password[i - 1][2] + password[i - 1][6]) % 1234567;
				break;
			case 4:
				password[i][j] = (password[i - 1][1] + password[i - 1][5] + password[i - 1][7]) % 1234567;
				break;
			case 5:
				password[i][j] = (password[i - 1][2] + password[i - 1][4] + password[i - 1][6] + password[i - 1][8]) % 1234567;
				break;
			case 6:
				password[i][j] = (password[i - 1][3] + password[i - 1][5] + password[i - 1][9]) % 1234567;
				break;
			case 7:
				password[i][j] = (password[i - 1][4] + password[i - 1][8] + password[i - 1][0]) % 1234567;
				break;
			case 8:
				password[i][j] = (password[i - 1][5] + password[i - 1][7] + password[i - 1][9]) % 1234567;
				break;
			case 9:
				password[i][j] = (password[i - 1][6] + password[i - 1][8]) % 1234567;
				break;
			}
		}
	}

	for (long long len : testcase)
	{
		long long res = 0;

		for (long long i = 0; i < 10; ++i)
		{
			res += password[len][i];
			res %= 1234567;
		}

		cout << res << endl;
	}
}


int main()
{
	long long T;
	cin >> T;

	vector<long long> testcase(T);

	for (long long i = 0; i < T; ++i)
	{
		cin >> testcase[i];
	}

	for (long long i = 0; i < 10; ++i)
	{
		password[1][i] = 1;		// 비밀번호 길이가 1일 때
	}

	solution(T, testcase);

	return 0;
}