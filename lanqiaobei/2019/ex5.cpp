/* 看不懂，放弃 */



#include <iostream>
#include <queue>
using namespace std;
char a[35][55];
int book[35][55];
int ne[4][2] = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}}; // 竖直方向，水平方向
struct dd
{
    int x;
    int y;
    string s;
    dd(int xx, int yy, string ss)
    {
        x = xx;
        y = yy;
        s = ss;
    }
};
void bfs(int x, int y)
{
    queue<dd> q;
    dd temp(0, 0, "");
    book[x][y] = 1;
    q.push(temp);
    while (q.empty() == 0)
    {
        temp = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            string z;
            int tx = temp.x + ne[i][0];
            int ty = temp.y + ne[i][1];
            if (i == 0)
                z = "D";
            else if (i == 1)
                z = "L";
            else if (i == 2)
                z = "R";
            else
                z = "U";
            if (tx < 0 || tx >= 30 || ty < 0 || ty >= 50)
                continue;
            if (book[tx][ty] == 1)
                continue;
            if (a[tx][ty] == '0')
            {
                book[tx][ty] = 1;
                q.push(dd(tx, ty, temp.s + z));
            }
            if (tx == 29 && ty == 49)
            {
                cout << temp.s + z << endl;
                return;
            }
        }
    }
}
int main()
{
    int i, j;
    for (i = 0; i < 30; i++)
        cin >> a[i];
    bfs(0, 0);
    system("pause");
    return 0;
}
