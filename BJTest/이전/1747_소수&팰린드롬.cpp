#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int N;

// 2 ~ 해당 숫자의 제곱근까지의 숫자 중에서 해당 숫자를 나눴을 때
// 나누어 떨어지는 것이 있다면 소수가 아니고, 없다면 소수다 (제곱근을 기준으로 짝을 이루기 때문)
// 81의 제곱근은 9이고 81의 약수는 1, 3, 9, 27, 81
// 9를 기준으로 1, 81 / 3, 27 짝을 이룬다 -> 따라서 2 ~ 제곱근까지만 확인해도 됨

void input()
{
	cin >> N;
}

bool IsPrime(int num)
{
	if (num < 2)
	{
		return false;
	}

	int sqrtNum = (int)sqrt(num);

	for (int i = 2; i <= sqrtNum; ++i)
	{
		if (num % i == 0)
		{
			return false;
		}
	}
	
	return true;
}

bool IsPalindrome(int num)
{
	string s1 = to_string(num);
	string s2 = s1;
	reverse(s2.begin(), s2.end());

	if (s1 == s2)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void solution()
{
	int num = N;

	while (!IsPrime(num) || !IsPalindrome(num))
	{
		++num;
	}

	cout << num << endl;
}


int main()
{
	input();
	solution();

	return 0;
}