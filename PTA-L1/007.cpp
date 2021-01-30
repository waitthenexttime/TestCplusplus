/* 
1.string类型容器可直接初始化，如vector<string> pinyin = {"ling", "yi", "er", "san"}；
2.for(auto it:result)返回类型不是迭代器，而是所存元素类型
3.迭代器是指针，返回值要*
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    string num;
    cin >> num;
    vector<string> pinyin = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu", "fu"};
    int flag;
    for (int i = 0; i < num.size() - 1; ++i)
    {
        if (num[i] == '-')
        {
            flag = 10;
            cout << pinyin[10] << " ";
        }
        else
        {
            flag = num[i] - '0';
            cout << pinyin[flag] << " ";
        }
    }
    cout << pinyin[*(num.end() - 1) - '0'];
    system("pause");
    return 0;
}