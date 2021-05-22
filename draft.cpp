/* 

*/

#include <iostream>
#include <deque>
using namespace std;

int main()
{
    deque<int> q;
    for (int i = 0; i < 5; i++)
    {
        q.push_back(i);
    }
    for (int it : q)
    {
        cout << it << " ";
    }
    q.pop_back();
    cout << endl;
    for (int it : q)
    {
        cout << it << " ";
    }
    cout << endl;
    q.push_front(1000);
    for (int it : q)
    {
        cout << it << " ";
    }
    cout << endl;
    q.pop_front();
    for (int it : q)
    {
        cout << it << " ";
    }
    cout << endl;
    system("pause");
    return 0;
    /* 
    0 1 2 3 4
    0 1 2 3
    1000 0 1 2 3
    0 1 2 3 
    */
}