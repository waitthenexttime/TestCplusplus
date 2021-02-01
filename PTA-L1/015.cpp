/* 

*/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    int i, j, m, p;
    char n;
    scanf("%d %c", &m, &n);
    if (m < 3 || m > 21)
    {
        exit(0);
    }
    if (m % 2 == 0)
        p = m / 2; //四舍五入的应用
    else
        p = m / 2 + 1;
    for (i = 0; i < p; i++) //双重循环输出
    {
        for (j = 0; j < m; j++)
        {
            printf("%c", n);
        }
        printf("\n");
    }
    system("pause");
    return 0;
}
