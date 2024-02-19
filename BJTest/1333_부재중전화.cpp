#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// l초부터 l+4초까지 벨소리를 들을 수 있음
// d가 만약 그 사이에 있다면 d가 가장 빠른 시간
// 만약 그 사이에 없었다면 다음 들을 수 있는 시간은 (l + 5)초를 더한 값
// 즉, 2l + 5초부터 2l + 9초까지가 된다
// 벨소리 d가 가질 수 있는 범위는 left보다 작을 때, left와 left+4 사이에 있을 때
// left + 4보다 클 때로 나눌 수 있다

bool check(int left, int d)
{
	if (left <= d && left + 4 >= d)
	{
		return true;
	}

	return false;
}

void solution(int n, int l, int d)
{
	int end = n * (l + 5);
	int song = l;
	int bell = d;

	while (true)
	{
		// 다음 벨이 모든 노래가 끝났을 때 울린다면 무조건 들을 수 있다
		if (d >= end)
		{
			cout << d << endl;
			return;
		}
		
		if (check(l, d))
		{
			cout << d << endl;
			return;
		}
		// d가 l보다 작거나, d가 l + 4보다 크거나
		else
		{
			if (d < l)
			{
				d += bell;
			}
			else if (d > l + 4)
			{
				l += song + 5;
			}
		}
	}
}

int main()
{
	int N, L, D;
	cin >> N >> L >> D;

	solution(N, L, D);

	return 0;	
}