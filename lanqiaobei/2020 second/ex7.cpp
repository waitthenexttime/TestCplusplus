/* 

*/

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

bool flag1 = false;
bool flag2 = false;

string check1(string year)
{
    reverse(year.begin(), year.end());
    return year;
}
string check2(string year)
{
    reverse(year.begin(), year.end());
    return year;
}
bool check3(string year)
{
    string a = year.substr(0, 2);
    string b = year.substr(2, 4);
    if (a == b)
    {
        return true;
    }
    return false;
}

int main()
{
    int N;
    cin >> N;
    for (int i = N + 1; i <= 89991231; i++)
    {
        string word = to_string(i);
        string year = word.substr(0, 4);
        string date = word.substr(4, 8);

        if (date == check1(year) && !flag1)
        {
            cout << i << endl;
            flag1 = true;
        }
        if (date == check2(year) && check3(year) && check3(date) && !flag2)
        {
            cout << i;
            flag2 = true;
        }
        if (flag1 && flag2)
        {
            break;
        }
    }

    cout << endl;
    system("pause");
    return 0;
}