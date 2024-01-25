#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool IsFind = false;

bool IsGood(string s)
{
    int n = (int)s.length();

    for (int i = 1; i <= n / 2; ++i)
    {
        string s1 = s.substr(n - (i * 2), i);
        string s2 = s.substr(n - i, i);

        if (s1 == s2)
        {
            return false;
        }
    }

    return true;
}

void solution(int idx, int N, string s)
{
    if (!IsGood(s) || IsFind)
    {
        return;
    }

    if (idx == N)
    {
        cout << s << endl;
        IsFind = true;

        // exit(0)을 쓰면 동일한 효과를 얻을 수 있다
        // exit() -> stdlib.h 필요
        // exit(0) == return 0;
    }

    solution(idx + 1, N, s + "1");
    solution(idx + 1, N, s + "2");
    solution(idx + 1, N, s + "3");
}

int main()
{
    int N;
    cin >> N;

    string res = "";

    solution(0, N, res);

    cout << res << endl;
     
    return 0;
}