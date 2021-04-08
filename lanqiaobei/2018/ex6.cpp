/* 

*/

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int N,t;
    cin >> N;
    vector<int> A;
    vector<int> B;
    vector<int> C;

    for (int i = 0; i < N; i++)
    {
        cin >> t;
        A.push_back(t);
    }
    for (int i = 0; i < N; i++)
    {
        cin >> t;
        B.push_back(t);
    }
    for (int i = 0; i < N; i++)
    {
        cin >> t;
        C.push_back(t);
    }
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (B[j] > A[i])
            {
                for (int k = 0; k < N; k++)
                {
                    if (C[k] > B[j])
                    {
                        sum++;
                    }
                }
            }
        }
    }
    cout<<sum;

    cout << endl;
    system("pause");
    return 0;
}