/* 问题是岛屿数，不是陆地数！！！
这题用dfs
在每个岛屿中递归查询
*/

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
char map[1005][1005];
int book[1005][1005];
int n;
int Next[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
bool flag = false;
void dfs(int x, int y)
{
    cout<<"x:"<<x<<" y:"<<y<<endl;
    for (int k = 0; k < 4; k++)
    {
        int tx = x + Next[k][0];
        int ty = y + Next[k][1];
        if (map[tx][ty] == '#' && book[tx][ty] == 0)
        {
            book[tx][ty] = 1;
            if (map[tx - 1][ty] == '#' && map[tx + 1][ty] == '#' && map[tx][ty - 1] == '#' && map[tx][ty + 1] == '#')
            {
                cout<<"!!!!!"<<x<<y<<"tx:"<<tx<<ty<<endl;
                flag = true;
            }
            dfs(tx, ty);
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> map[i][j];
        }
    }
    int cnt1 = 0, cnt2 = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (map[i][j] == '#' && book[i][j] == 0)
            {
                flag == false;
                book[i][j] = 1;
                dfs(i, j);
                cnt1++;
                if (flag)
                {
                    cnt2++;
                }
                cout << cnt1 << " " << cnt2 << endl;
            }
        }
    }
    cout << endl;
    system("pause");
    return 0;
}