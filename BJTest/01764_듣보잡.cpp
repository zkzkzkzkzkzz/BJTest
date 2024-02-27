#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;




void solution(map<string, int>& name)
{
	vector<string> nothing;

	for (auto m : name)
	{
		if (2 == m.second)
		{
			nothing.push_back(m.first);
		}
	}

	sort(nothing.begin(), nothing.end());

	int size = nothing.size();

	cout << size << endl;

	for (int i = 0; i < size; ++i)
	{
		cout << nothing[i] << endl;
	}
}


int main()
{
	int N, M;
	cin >> N >> M;

	map<string, int> name;

	for (int i = 0; i < N; ++i)
	{
		string unheard;
		cin >> unheard;
		++name[unheard];
	}

	for (int j = 0; j < M; ++j)
	{
		string unseen;
		cin >> unseen;
		++name[unseen];
	}

	solution(name);

	return 0;
}