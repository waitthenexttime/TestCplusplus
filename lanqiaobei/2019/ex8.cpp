/* 
要考虑类似 1 3 8 这种情况
虽然d=2,但不是等差数列，可以将每一项与第一项差值%d
考虑 2 2 2 2 2，d=0，直接输出n
*/

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    vector<int> sequence;
    int N, n;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        sequence.push_back(x);
    }
    sort(sequence.begin(), sequence.end());
    int mind = INT32_MAX;
    for (int i = 1; i < N; i++)
    {
        int d = fabs(sequence[i] - sequence[i - 1]);
        mind = min(mind, d);
    }
    if (!mind)
    {
        n = N;
    }
    else
    {
        bool judge = true;
        for (int i = 1; i < N; i++)
        {
            int t = sequence[i] - sequence[0];
            if (t % mind != 0)
            {
                judge = false;
            }
        }
        if (judge)
        {
            n = 1 + (sequence[N - 1] - sequence[0]) / mind;
        }
        else
        {
            n = 1 + (sequence[N - 1] - sequence[0]);
        }
    }
    cout<<n;
    cout << endl;
    system("pause");
    return 0;
}