/* 
https://img-blog.csdn.net/20180406212258821
*/

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    int X, Y;
    cin >> X >> Y;
    int dis;
    int t = max(abs(X), abs(Y));
    if (X >= 0 && Y >= 0)
    {
        if (X == Y)
        {
            dis = 4 * pow(t, 2);
        }
        if (X > Y)
        {
            dis = 4 * pow(t, 2) + t - Y;
        }
        if (X < Y)
        {
            dis = 4 * pow(t, 2) + t - X;
        }
    }
    if (X >= 0 && Y <= 0)
    {
        if (X == -Y)
        {
            dis = 2 * t * (2 * t + 1);
        }
        if (X > -Y)
        {
            dis = 2 * t * (2 * t + 1) - (t + Y);
        }
        if (X < -Y)
        {
            dis = 2 * t * (2 * t + 1) + (t - X);
        }
    }
    if (X <= 0 && Y >= 0)
    {
        if (-X == Y)
        {
            dis = 2 * t * (2 * t - 1);
        }
        if (-X > Y)
        {
            dis = 2 * t * (2 * t - 1) - (t - Y);
        }
        if (-X < Y)
        {
            dis = 2 * t * (2 * t - 1) - (t + X);
        }
    }
    if (X <= 0 && Y <= 0)
    {
        t = max(abs(X), abs(Y) + 1);
        dis = pow(t + t - 1, 2) + abs(X) - abs(Y) - 1;
    }
    cout << dis;
    cout << endl;
    system("pause");
    return 0;
}