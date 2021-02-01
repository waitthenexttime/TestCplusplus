

/* 

*/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int func(int n)
{
    if (n == 1)
    {
        return 1;
    }
    else
    {
        return n * func(n - 1);
    }
}

int main()
{
    int N,sum =0;
    cin >> N;
    for (int i = 1; i <=N ; i++)
    {
        sum += func(i);
    }
    cout<<sum;
    cout << endl;
    system("pause");
    return 0;
}
