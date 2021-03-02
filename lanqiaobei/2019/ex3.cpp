/* 

*/

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int a = 1, b = 1, c = 1, res;
    for (int i = 4; i <= 20190324; i++)
    {
        res = (a+b+c)%10000;
        a=b;
        b=c;
        c=res;
    }
    cout<<res;
    cout << endl;
    system("pause");
    return 0;
}