/* 
学会如何二进制与十进制转换
int t = n % 2;
n /= 2;
a[k--] = t;

注意负数，负数在计算机中是以补码的方式储存的，
比如-1的原码是【1000 0001】
反码是【1111 1110】（按位取反）
补码是【1111 1111】（相加）
等同于127的原码，所以对于负数，可以+128后处理。
*/

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int m = 10, n;
    while (m--)
    {
        for (int i = 1; i <= 32; i++)
        {
            cin >> n;
            if (n < 0)
                n += 128;
            int a[10] = {0}, k = 8;
            while (n)
            {
                int t = n % 2;
                n /= 2;
                a[k--] = t;
            }
            for (int j = 1; j <= 8; j++)
            {
                if (a[j] == 0)
                    cout << ' ';
                else
                    cout << '#';
            }
            if (i % 2 == 0)
                cout << endl;
        }
        cout << endl;
    }
    system("pause");
    return 0;
}
/*
答案：81
*/