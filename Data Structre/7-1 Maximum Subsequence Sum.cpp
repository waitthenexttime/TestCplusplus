// 7-1 最大子列和问题

/* 
递归分而治之代码很烦
相比而言在线处理效率最高
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

// 时间复杂度N^2
int Maximum_Subsequence_Sum1(vector<int> a, int N)
{
    int Max = 0, sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum = 0;
        for (int j = i; j < N; j++)
        {
            sum += a[j];
            Max = max(Max, sum);
        }
    }
    return Max;
}

// 分而治之,递归分成两份，分别求每个分割后子列的最大和, 时间复杂度N*logN
int Max3(int A, int B, int C)
{
    return (A > B) ? ((A > C) ? A : C) : ((B > C) ? B : C);
}
int DivideAndConquer(vector<int> a, int left, int right)
{
    if (left == right)
    {
        if (a[left] > 0)
        {
            return a[left];
        }
        else
        {
            return 0;
        }
    }
    // 分别找到左右最大子列和
    int center = (left + right) / 2;
    int MaxLeftSum = DivideAndConquer(a, left, center);
    int MaxRightSum = DivideAndConquer(a, center + 1, right);

    // 再分别找左右跨界最大子列和
    int MaxLeftBorderSum = 0;
    int LeftBorderSum = 0;
    for (int i = center; i >= left; i--)
    {
        LeftBorderSum += a[i];
        if (MaxLeftBorderSum < LeftBorderSum)
        {
            MaxLeftBorderSum = LeftBorderSum;
        }
    }
    int MaXRightBorderSum = 0;
    int RightBorderSum = 0;
    for (int i = center + 1; i <= right; i++)
    {
        RightBorderSum += a[i];
        if (MaXRightBorderSum < RightBorderSum)
        {
            MaXRightBorderSum = RightBorderSum;
        }
    }
    // 返回左边最大子列和，右边最大子列和和跨界最大子列和三者中最大值
    return Max3(MaxLeftSum, MaxRightSum, MaxLeftBorderSum + MaXRightBorderSum);
}

int Maximum_Subsequence_Sum2(vector<int> a, int N)
{
    return DivideAndConquer(a, 0, N - 1);
}

// 在线处理,直接累加，如果累加到当前的和为负数，置当前值或0 时间复杂度N
int Maximum_Subsequence_Sum3(vector<int> a, int N)
{
    int Max = 0, sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum += a[i];
        Max = max(Max, sum);
        if (sum < 0)
        {
            sum = 0;
        }
    }
    return Max;
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
    cout << Maximum_Subsequence_Sum1(a, N) << endl;
    cout << Maximum_Subsequence_Sum2(a, N) << endl;
    cout << Maximum_Subsequence_Sum3(a, N) << endl;
    cout << endl;
    system("pause");
    return 0;
}