/* 

*/

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

bool Judge(int a)
{
    string s = to_string(a);
    if (s.find('2') != string::npos || s.find('4') != string::npos)
    {
        return false;
    }
    return true;
}

int main()
{
    int N;
    int count=0;
    cin >> N;
    for (int i = 1; i < N / 3; i++)
    {
        if (!Judge(i))
        {
            continue;
        }
        for (int j = i + 1; j <N; j++)
        {
            int k = N - i - j;
            if (!Judge(j) || !Judge(k) || k<=j)
            {
                continue;
            }
            count++;
        }
    }
    cout<<count<<endl;
    cout << endl;
    system("pause");
    return 0;
}