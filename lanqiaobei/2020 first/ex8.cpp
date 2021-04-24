/* 

*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int Next[2][2] = {{0, 1}, {1, 0}};
int counter = 0;
int n, m;
int dp[35][35];
void dfs(int x, int y)
{
    for (int i = 0; i < 2; i++)
    {
        int tmpx = x + Next[i][0];
        int tmpy = y + Next[i][1];
        if ((tmpx % 2 || tmpy % 2) && (tmpx <= n && tmpy <= m))
        {
            if (tmpx == n && tmpy == m)
            {
                counter++;
                continue;
            }
            dfs(tmpx, tmpy);
        }
    }
}

int main()
{
    cin >> n >> m;
    dfs(1, 1);
    cout << counter;
    cout << endl;
    system("pause");
    return 0;
}