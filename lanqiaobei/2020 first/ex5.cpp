/* 

*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int dp[1020][1020];
int main()
{
    dp[0][0] = 1; // 两行一个数字都不放，也是一种方案
    for (int i = 0; i <= 1010; i++)
        for (int j = 0; j <= 1010; j++)
        {
            if (i - 1 >= j) // 转移前的状态也要合法，即第一行的数量不小于第二行的数量
                dp[i][j] += dp[i - 1][j] % 2020;
            if (j)
                dp[i][j] += dp[i][j - 1] % 2020;
        }

    cout << dp[1010][1010] << endl;
    cout << endl;
    system("pause");
    return 0;
}