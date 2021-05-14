// Data Structures and Algorithms 7-1 Maximum Subsequence Sum

/* 
平台负数和零跑不过
个人认为代码没问题
这里用的是在线处理，要考虑最大子列的左右值
这里是在用一个临时变量存储和小于零后子列的左值变化的情况
如果Max也变化，临时变量转正
*/

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

void Maximum_Subsequence_Sum(vector<int> a, int N)
{
    int Max = 0;
    int sum = 0;
    int finalleft = 0, templeft = 0, right = N - 1;
    for (int i = 0; i < N; i++)
    {

        sum += a[i];
        if (sum > Max)
        {
            Max = sum;
            finalleft = templeft;
            right = i;
        }
        if (sum < 0)
        {
            sum = 0;
            templeft = i + 1;
        }
    }
    cout << Max << " " << a[finalleft] << " " << a[right];
}

int main()
{
    int N;
    vector<int> a;
    cin >> N;
    for (int i = 0, x; i < N; i++)
    {
        cin >> x;
        a.push_back(x);
    }
    Maximum_Subsequence_Sum(a, N);
    cout << endl;
    system("pause");
    return 0;
}