/* 

*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int main()
{
    int n, K;
    cin >> n >> K;
    vector<int> A;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        A.push_back(t);
    }
    int counter = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                continue;
            }
            counter++;
        }
    }
    cout<<counter;
    cout << endl;
    system("pause");
    return 0;
}