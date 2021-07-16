#include <iostream>
#include <vector>
#include <map>
using namespace std;

int candy(vector<int> &ratings)
{
    int n = ratings.size();
    int ret = 1;
    int inc = 1, dec = 0, pre = 1;
    for (int i = 1; i < n; i++)
    {
        
        if (ratings[i] >= ratings[i - 1])
        {
            dec = 0;
            pre = ratings[i] == ratings[i - 1] ? 1 : pre + 1;
            ret += pre;
            inc = pre;
        }
        else
        {
            dec++;
            if (dec == inc)
            {
                dec++;
            }
            ret += dec;
            pre = 1;
        }

    }
    return ret;
}

int main()
{
    vector<int> a = {1, 3, 5, 3, 2, 1};
    cout << candy(a);
    system("pause");
    return 0;
}
