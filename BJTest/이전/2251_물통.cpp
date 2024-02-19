#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int A, B, C, sum;
bool visit[201][201];
bool res[201];
queue<pair<int, int>> q;		// 첫번째 물통의 양, 두번째 물통의 양


// 한 물통에서 다른 물통으로 물을 옮길 때
// 두 물통에 각각 현재 들어있는 물의 양의 합이 채우려는 물통의 크기보다 크거나
// 두 물통에 각각 현재 들어있는 물의 양의 합이 채우려는 물통의 크기보다 작거나 같은 경우

// A 물통에는 마지막엔 항상 비어있어야 하므로
// B, C 물통의 합이 항상 C의 부피와 같아야 한다

void input()
{
	cin >> A >> B >> C;
}

void solution()
{
	visit[0][0] = true;
	res[C] = true;	// C물통에만 가득 차있으므로 손실되는 물이 없으면 총 물의 양은 C의 부피와 같음
	sum = C;		// 총 물의 양
	q.push({ 0,0 });

	while (!q.empty())
	{
		int one = q.front().first;
		int two = q.front().second;
		int three = sum - (one + two);
		q.pop();

		// 현재 각 물통에 담긴 물의 양
		int CurOne = one;
		int CurTwo = two;
		int CurThree = three;
		
		// 1. A물통 -> B물통
		CurTwo += CurOne;
		CurOne = 0;
		// A에서 B물통으로 옮기려는데 넘친다면
		if (CurTwo >= B)
		{
			CurOne = CurTwo - B;
			CurTwo = B;
		}
		if (!visit[CurOne][CurTwo])
		{
			visit[CurOne][CurTwo] = true;
			q.push({ CurOne, CurTwo });

			if (CurOne == 0)
			{
				res[CurThree] = true;
			}
		}


		// 2. A물통 -> C물통
		CurOne = one; CurTwo = two, CurThree = three;
		CurThree += CurOne;
		CurOne = 0;
		// A에서 C물통으로 옮기려는데 넘친다면
		if (CurThree >= C)
		{
			CurOne = CurThree - C;
			CurThree = C;
		}
		if (!visit[CurOne][CurTwo])
		{
			visit[CurOne][CurTwo] = true;
			q.push({ CurOne, CurTwo });

			if (CurOne == 0)
			{
				res[CurThree] = true;
			}
		}

		// 3. B물통 -> A물통
		CurOne = one; CurTwo = two, CurThree = three;
		CurOne += CurTwo;
		CurTwo = 0;

		if (CurOne >= A)
		{
			CurTwo = CurOne - A;
			CurOne = A;
		}
		if (!visit[CurOne][CurTwo])
		{
			visit[CurOne][CurTwo] = true;
			q.push({ CurOne, CurTwo });

			if (CurOne == 0)
			{
				res[CurThree] = true;
			}
		}

		// 4. B물통 -> C물통
		CurOne = one; CurTwo = two, CurThree = three;
		CurThree += CurTwo;
		CurTwo = 0;
		if (CurThree >= C)
		{
			CurTwo = CurThree - C;
			CurThree = C;
		}
		if (!visit[CurOne][CurTwo])
		{
			visit[CurOne][CurTwo] = true;
			q.push({ CurOne, CurTwo });

			if (CurOne == 0)
			{
				res[CurThree] = true;
			}
		}

		// 5. C물통 -> A물통
		CurOne = one; CurTwo = two, CurThree = three;
		CurOne += CurThree;
		CurThree = 0;
		if (CurOne >= A)
		{
			CurThree = CurOne - A;
			CurOne = A;
		}
		if (!visit[CurOne][CurTwo])
		{
			visit[CurOne][CurTwo] = true;
			q.push({ CurOne, CurTwo });

			if (CurOne == 0)
			{
				res[CurThree] = true;
			}
		}

		// 6. C물통 -> B물통
		CurOne = one; CurTwo = two, CurThree = three;
		CurTwo += CurThree;
		CurThree = 0;
		if (CurTwo >= B)
		{
			CurThree = CurTwo - B;
			CurTwo = B;
		}
		if (!visit[CurOne][CurTwo])
		{
			visit[CurOne][CurTwo] = true;
			q.push({ CurOne, CurTwo });

			if (CurOne == 0)
			{
				res[CurThree] = true;
			}
		}
	}

	for (int i = 0; i <= C; ++i)
	{
		if (res[i])
		{
			cout << i << " ";
		}
	}
}


int main()
{
	input();
	solution();

	return 0;
}