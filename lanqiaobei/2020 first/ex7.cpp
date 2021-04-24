/* 

*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int main()
{
    string word;
    cin >> word;
    for (int i = 0; i < word.length(); i++)
    {
        char tmp = word[i];
        if (tmp >= '0' && tmp <= '9')
        {
            int n = (tmp - '0') - 1;
            for (int j = 0; j < n; j++)
            {
                cout << word[i - 1];
            }
        }
        else
        {
            cout << tmp;
        }
    }

    cout << endl;
    system("pause");
    return 0;
}