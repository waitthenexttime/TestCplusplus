/* 
不正确
*/

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int plus, cut;
    cin >> plus >> cut;
    int N = plus + cut + 1;
    vector<int> num;
    for (int i = 0, t; i < N; i++)
    {
        cin >> t;
        num.push_back(t);
    }
    sort(num.begin(), num.end());
    int cut_sum = *num.begin(), plus_sum = 0;
    for (int i = 1; i < cut; i++)
    {
        cut_sum -= num[i];
    }
    for (int i = cut; i < N; i++)
    {
        plus_sum += num[i];
    }
    cout << plus_sum - cut_sum;
    cout << endl;
    system("pause");
    return 0;
}