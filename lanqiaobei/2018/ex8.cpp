/* 

*/

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

struct dianzan
{
    int ts, id;
};

bool cmp(dianzan a, dianzan b)
{
    if (a.id == b.id)
    {
        return a.ts < b.ts;
    }
    return a.id < b.id;
}
int main()
{
    int N, D, K;
    cin >> N >> D >> K;
    vector<dianzan> list;
    for (int i = 0; i < N; i++)
    {
        dianzan tmp;
        cin >> tmp.ts >> tmp.id;
        list.push_back(tmp);
    }
    sort(list.begin(), list.end(), cmp);
    dianzan start;
    start.ts = -1;
    start.id = -1;
    int counter = 0;
    for (int i = 0; i < N; i++)
    {
        if (counter == K)
        {
            counter = 0;
            cout << start.id << endl;
        }
        if (start.id != list[i].id)
        {
            start = list[i];
            counter = 0;
        }
        if (list[i].ts < start.ts + D)
        {
            counter++;
        }
    }
    cout << endl;
    system("pause");
    return 0;
}