/* 

*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int gcd(int m, int n)
{
    int t = m % n;
    while (t)
    {
        m = n;
        n = t;
        t = m % n;
    }
    if (n == 1)
    {
        return true;
    }
    return false;
}

int main()
{
    int num = 0;
    for (int i = 1; i <= 2020; i++)
    {
        for (int j = 1; j <= 2020; j++)
        {
            if (gcd(i, j))
            {
                num++;
            }
        }
    }
    cout << num;
    cout << endl;
    system("pause");
    return 0;
}