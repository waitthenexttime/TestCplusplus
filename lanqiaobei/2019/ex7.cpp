/* 
max_element用来寻找数组中最大值
2个参数为数组首地址，数组尾地址
返回值为指向最大值地址的指针，所以求最大值要在前面加*
该指针减去首地址就是最大值下标值，类型为int
*/




#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    int N;
    cin>>N;
    int maxweightsum,maxdepth;
    int depth = 0;
    int k=1;
    while (N)
    {
        depth++;
        int sum=0;
        for (int i = 0; i < min(N,k); i++) // min(N,k)是因为树不一定是满二叉树
        {
            int x;
            cin>>x;
            sum+=x;
            N--;
        }
        if (sum>maxweightsum)
        {
            maxweightsum=sum;
            maxdepth=depth;
        }
        k = pow(2,depth);
    }
    cout<<maxdepth;
    cout << endl;
    system("pause");
    return 0;
}



