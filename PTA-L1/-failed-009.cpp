#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;


void split(long int &A, long int &B)
{
    long int g = __gcd(A, B); //求最大公因数
    A /= g;                   //约分
    B /= g;
}
int main(void)
{
    int N;
    int long a, b, x, y;
    cin >> N;
    scanf("%ld/%ld", &a, &b);
    for (int i = 1; i < N; i++)
    {
        scanf("%ld/%ld", &x, &y);
        a = a * y + x * b;
        b = b * y;
        split(a, b);
    }
    if (N == 1)
        split(a, b);
    if (a == 0)
        cout << 0;
    else if (a / b == 0)
        cout << a << "/" << b;
    else if (a % b)
        cout << a / b << " " << a % b << "/" << b;
    else
        cout << a / b;
    cout << endl;
    system("pause");
    return 0;
}