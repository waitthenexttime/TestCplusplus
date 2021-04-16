/* 
7
80
92
56
74
88
100
0
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
    cin >> N;
    vector<int> a;
    for (int i = 0; i < N; i++)
    {
        int t;
        cin >> t;
        a.push_back(t);
    }
    double jige = 0;
    double youxiu = 0;
    for (int i = 0; i < N; i++)
    {
        if (a[i] >= 60)
        {
            jige++;
            if (a[i] >= 85)
            {
                youxiu++;
            }
        }
    }
    cout << round(jige * 100 / N) <<"%"<< endl;
    cout << round(youxiu * 100 / N)<<"%";

    cout << endl;
    system("pause");
    return 0;
}