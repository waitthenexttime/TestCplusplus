#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    for (auto it1 : s1)
    {
        int i;
        for (i = 0; i < s2.length(); i++)
        {
            if (it1 == s2[i])
            {
                break;
            }
        }
        if (i == s2.length())
        {
            cout << it1;
        }
    }
    cout << endl;
    system("pause");
    return 0;
}