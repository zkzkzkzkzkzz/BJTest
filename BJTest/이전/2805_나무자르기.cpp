#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int solution(int m, vector<int> trees)
{
	sort(trees.begin(), trees.end());

	// int 썼더니 범위에서 벗어난 듯 -> 틀렸다고 자꾸 그럼
	long long minheight = trees[0];
	long long Maxheight = trees[(int)trees.size() - 1];
	long long cutheight = 0;

	while (minheight <= Maxheight)
	{
		long long midheight = minheight + (Maxheight - minheight) / 2;
		long long sum = 0;

		for (size_t i = 0; i < trees.size(); ++i)
		{
			if (trees[i] > midheight)
			{
				sum += trees[i] - midheight;
			}
		}

		if (sum < m)
		{
			Maxheight = midheight - 1;
		}
		// 적어도 m 이상 나무를 잘라갈 것이기 때문에
		// 굳이 m을 딱 맞출 필요는 없다
		else
		{
			// 만약 현재 저장된 자를 높이보다 midheight가 더 크다면
			// 더 높게 잘라도 m 이상 자를 수 있다는 것
			// 최댓값을 그러므로 갱신해준다
			if (midheight > cutheight)
			{
				cutheight = midheight;
			}

			minheight = midheight + 1;
		}
	}

	return cutheight;
}


int main()
{
	vector<int> trees = { 20, 15 ,10 ,17 };

	long long res = solution(7, trees);

	cout << res << endl;

	return 0;
}