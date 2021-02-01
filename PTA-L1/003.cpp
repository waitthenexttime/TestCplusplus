/* 
count函数在算法模块中，可以计算数组，字符串里元素出现次数
*/


#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string numbers;
    cin >> numbers;
    for (int i = 0; i < 10; i++)
    {
        int num = count(numbers.begin(), numbers.end(), char('0' + i));
        if (num != 0)
        {
            cout << i << ':' << num << endl;
        }
    }
    system("pause");
    return 0;
}