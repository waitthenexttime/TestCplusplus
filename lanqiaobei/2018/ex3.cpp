/* 
string tmp = num.substr(num.length() - 1); // string截取
a[i] = stoi(tmp);   // string转int类型

两个数相乘 4*25 = 100
4能分出2个2
25能分出2个5
因此凑成2个10
又如 104 * 2125
104 = 2 * 2 * 2 * 13
2125 = 5 * 5 * 5 * 17
应有 3个10
104 * 2125 = 221000
*/

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int count_2 = 0, count_5 = 0;
    int a[100];
    for (int i = 0; i < 100; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < 100; i++)
    {
        int t = a[i];
        while (t % 2 == 0)
        {
            count_2++;
            t /= 2;
        }
        t = a[i];
        while (t % 5 == 0)
        {
            count_5++;
            t /= 5;
        }
    }
    cout<<min(count_2,count_5);
    cout << endl;
    system("pause");
    return 0;
}
