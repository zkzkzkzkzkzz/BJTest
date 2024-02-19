#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void solution(string& seats, int N)
{
	int cup = 0;
	
	// 컵을 좌석 왼쪽에만 둔다 가정했을 때
	// 커플 좌석이 하나 생길 때마다 둘 중 한명은 컵홀더가 없음
	for (int i = 0; i < (int)seats.size(); ++i)
	{
		// 일반 좌석이라면
		if (seats[i] == 'S')
		{
			++cup;
		}
		// 커플 좌석이라면
		else
		{
			++cup;
			++i;	// 커플석은 두자리가 한 쌍이기에 i를 하나더 증가
		}
	}

	// 컵을 왼쪽에만 둔다고 가정했으니
	// 가장 오른쪽 컵 홀더는 빈 상태로 있게 된다
	// 이때 가장 오른쪽에 있는 좌석이 커플석이라면 왼쪽에 컵홀더가 없던 사람이 그 홀더를 사용하면 되고
	// 만약 일반석이었다면 커플석을 만나기 전까지 모두 왼쪽에 있던 컵홀더를 오른쪽으로 옮기면 된다
	// 그러면 왼쪽에 컵홀더가 없던 사람은 오른쪽에 빈 홀더가 생기게 되므로 그 홀더를 사용하면 된다
	// 즉, 마지막 빈 상태의 컵홀더를 사용하면 한명은 추가로 컵홀더를 사용할 수 있다 (무한호텔 방 옮기는 느낌)
	
	// 그런데 cup만큼 사용했을때(가장 오른쪽 컵 홀더를 안 쓴 경우) N명이 모두 컵홀더를 사용할 수 있었다면
	// 오른쪽 컵홀더는 사용할 필요가 없다 -> cup + 1, N 중 작은 값을 택하는 이유
	int res = min(cup + 1, N);

	cout << res << endl;
}



int main()
{
	int N;
	cin >> N;

	string seats;
	cin >> seats;

	solution(seats, N);

	return 0;
}