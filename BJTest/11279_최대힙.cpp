#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	priority_queue<int> pq;
	for (int i = 0; i < N; ++i)
	{
		int A;
		cin >> A;
		
		if (A == 0)
		{
			if (pq.empty())
			{
				cout << 0 << "\n";
			}
			else
			{
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else
		{
			pq.push(A);
		}
	}

	return 0;
}