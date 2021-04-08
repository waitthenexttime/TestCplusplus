/* 

*/

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int n = 1000;
    int m = 3;
    int dp[10][1005]; // [第几部手机][楼层数]
    for (int i = 1; i <= n; i++)
    {
        dp[1][i] = i;
    }
    for (int i = 2; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dp[i][j] = INT32_MAX;
            for (int k = 2; k <= j; k++)
            {
                
            }
        }
    }

    cout << endl;
    system("pause");
    return 0;
}