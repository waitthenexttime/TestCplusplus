/* 
当vector用erase方法参数是位置指针，如删除第一个元素(vec.begin()+0)
删除元素后vector的size变小，并且索引重置，这导致如果在循环里，你删除后自加，会跳过删除元素的后一个元素
所以删除后可以让i自减
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int N;
    cin >> N;
    string temp;
    vector<string> result;
    string M = "10X98765432";
    int weight[] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
    for (int i = 0; i < N; i++)
    {
        cin >> temp;
        result.push_back(temp);
    }
    for (auto n = 0; n < result.size();)
    {
        auto it = result[n];
        bool isnum = true;
        int sum = 0;
        for (int i = 0; i < it.length() - 1; i++)
        {
            if (it[i] - '0' < 0 && it[i] - '0' > 9)
            {
                isnum = false;
            }
            sum += (it[i] - '0') * weight[i];
        }
        if (isnum && M[sum % 11] == it[17])
        {
            result.erase(result.begin() + n);
        }
        else
        {
            n++;
        }
    }
    if (result.size() == 0)
    {
        cout << "All passed";
    }
    else
    {
        for (auto it = result.begin(); it != result.end(); it++)
        {
            cout << *it << endl;
        }
    }
    system("pause");
    return 0;
}