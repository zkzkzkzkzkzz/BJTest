#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool broke[10] = { false };

int GetPressChannel(int channel)
{
    if (channel == 0)
    {
        return broke[0] ? 0 : 1;
    }

    int pressCnt = 0;

    while (channel > 0)
    {
        // 해당 버튼이 고장났는가
        if (broke[channel % 10])
        {
            return 0;
        }

        // 만약 고장나지 않았다면 자릿수를 바꾸고
        // 입력 횟수를 1 증가한 후 반복문 다시 돌림
        channel /= 10;
        ++pressCnt;
    }

    return pressCnt;
}


void solution(int N, vector<int>& brokebtn, int start)
{
    // + 또는 - 버튼만 사용
    int route1 = abs(N - start);

    // 숫자 버튼 & +,- 둘 다 사용
    int route2 = 10000000;
  
    for (int i = 0; i < 1000000; ++i)
    {
        int cnt = GetPressChannel(i);
       
        if (cnt > 0)
        {
            route2 = min(route2, abs(N - i) + cnt);
        }
    }

    cout << min(route1, route2) << endl;
}


int main()
{
    int N, M;

    cin >> N;
    cin >> M;

    vector<int> brokebtn(M);

    for (int i = 0; i < M; ++i)
    {
        cin >> brokebtn[i];
        broke[brokebtn[i]] = true;
    }

    solution(N, brokebtn, 100);

    return 0;
}