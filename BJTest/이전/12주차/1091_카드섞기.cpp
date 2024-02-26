#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// N -> 카드 개수
// 수열 P는 각 카드가 어떤 플레이어에게 가야 하는지에 대한 정보
// 플레이어는 총 세명, 즉 수열 P에는 0, 1, 2만 들어있다
// 수열 S는 카드를 한 번 섞을 때, 카드가 섞이는 방법
// i번째 위치에 있던 카드는 S[i]번째 위치로 이동하게 된다

// 예시
// N : 3
// P : 2 0 1 -> 0번 카드는 2번 플레이어에게, 1번 카드는 0번 플레이어에게, 2번 카드는 1번 플레이어에게 보내야 함
// S : 1 2 0
//-> 카드를 한 번 섞으면 0번 카드는 1번 자리로, 1번 카드는 2번 자리로, 2번 카드는 0번 자리로

// 솔직히 문제 뭔 소린지 모르겠음
// 그냥 주어진 수열 P가 0, 1, 2 순서로 맞추기 위해 몇번 셔플해야하는가 물어보는 거 같음
// 수열 P가 섞이는 순서는 수열 S를 따른다

// 수열 P가 0, 1, 2순으로 되어있는가
// 즉, 플레이어에게 카드를 순서대로 줄 수 있는가
bool iscycle(int N, vector<int>& P)
{
	for (int i = 0; i < N; ++i)
	{
		if (P[i] % 3 != i % 3)
		{
			return false;
		}
	}

	return true;
}

// 섞은 카드의 순서가 초기 카드 순서와 동일한가
// 즉, 한바퀴를 돌았는가
bool isrotate(vector<int>& P, vector<int>& Origin)
{
	return P == Origin ? true : false;
}


vector<int> shuffle(int N, vector<int>& P, vector<int>& S)
{
	vector<int> temp(N);

	for (int i = 0; i < N; ++i)
	{
		int card = P[i];	// 수열 P에 i번째 사람이 받을 카드
		int moveto = S[i];		// 카드를 섞을 때 i번째에 있던 카드가 이동할 인덱스

		temp[moveto] = card;
	}

	P = temp;

	return P;
}


void solution(int N, vector<int>& P, vector<int>& S)
{
	int cnt = 0;

	// 만약 처음부터 플레이어에게 순서대로 줄 수 있었다면
	// 섞을 필요가 없으므로 바로 0 출력
	if (iscycle(N, P))
	{
		cout << cnt << endl;
		return;
	}

	vector<int> Origin(N);	// 수열 P 원본 저장
	Origin = P;

	while (true)
	{
		shuffle(N, P, S);	// 카드 섞기

		// 섞은 카드가 만약 한바퀴를 돌았거나, 0, 1, 2 순서를 만들었다면 반복문 break
		if (isrotate(P, Origin) || iscycle(N, P))
		{
			++cnt;
			break;
		}
		else
		{
			++cnt;
		}
	}

	if (iscycle(N,P))
	{
		cout << cnt << endl;
	}
	else
	{
		cout << -1 << endl;
	}
}

int main()
{
	int N;
	cin >> N;

	vector<int> P(N);
	vector<int> S(N);

	for (int i = 0; i < N; ++i)
	{
		cin >> P[i];
	}

	for (int i = 0; i < N; ++i)
	{
		cin >> S[i];
	}

	solution(N, P, S);

	return 0;
}