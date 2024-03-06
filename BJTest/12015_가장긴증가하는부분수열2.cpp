#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// lower_bound : 찾으려는 key값 이상인 숫자가 몇번 인덱스에서 처음으로 등장하는지 반환
// upper_bound : 찾으려는 key값 초과인 숫자가 몇번 인덱스에서 처음으로 등장하는지 반환
// 두 함수 모두 오름차순(또는 내림차순) 정렬이 되어있는 배열에 사용해야 한다


void solution(vector<int>& sequence)
{
	vector<int> res;
	res.push_back(sequence[0]);

	for (int i = 1; i < sequence.size(); ++i)
	{
		// 현재 숫자가 저장된 벡터의 마지막 숫자보다 크다면
		if (res.back() < sequence[i])
		{
			// res에 push_back
			res.push_back(sequence[i]);
		}
		// 현재 숫자가 저장된 벡터의 마지막 숫자보다 작거나 같다면
		else
		{
			// res에서 현재 숫자 이상인 인덱스를 찾는다
			int idx = lower_bound(res.begin(), res.end(), sequence[i]) - res.begin();

			// 해당 인덱스의 숫자를 현재 숫자로 치환
			res[idx] = sequence[i];
		}
	}

	cout << res.size() << endl;
}

int main()
{
	int N;
	cin >> N;

	vector<int> sequence(N);

	for (int i = 0; i < N; ++i)
	{
		cin >> sequence[i];
	}

	solution(sequence);

	return 0;
}