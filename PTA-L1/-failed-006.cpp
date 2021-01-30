/*
千万不要忘记素数这种情况，如果输入的值是素数，那么它的因子就是 1 和它本身了，
但是题目要求1不能打印，所以我们最终只需输出它本身就可以了 
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    int N; //输入所求的数字
    scanf("%d", &N);
    int count = 0;   //计数器
    int start = 0;   //标记起始位置
    int m_count = 0; //最大的因子个数
    for (int i = 2; i <= sqrt(N); i++)
    {
        count = 0;
        int t = N;
        int j = i;
        while (t % j == 0)
        {
            t = t / j;
            j++;
            count++;
        }
        if (count > m_count)
        {
            start = i;
            m_count = count;
        }
    }
    if (m_count)
    {
        printf("%d\n", m_count);
        for (int i = 0; i < m_count; i++)
        {
            printf("%d", start + i);
            if (i != m_count - 1)
            {
                printf("*");
            }
        }
    }
    else
    {
        printf("%d\n%d", 1, N);
    }
    system("pause");
    return 0;
}