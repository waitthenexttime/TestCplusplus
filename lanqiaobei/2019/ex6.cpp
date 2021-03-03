/* 
s.find_first_of("2019")!=string::npos
该函数用于str2有任意字符在str1中就会返回索引
*/

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

bool Contain(int n)
{
    string s = to_string(n);
    if (s.find_first_of("2019")!=string::npos)
    {
        return true;
    }
    return false;
}
int main()
{
    int N;
    cin >> N;
    int sum = 0;
    for (int i = 1; i <= N; i++)
    {
        if (Contain(i))
        {
            sum += i;
        }
    }
    cout << sum;
    cout << endl;
    system("pause");
    return 0;
}