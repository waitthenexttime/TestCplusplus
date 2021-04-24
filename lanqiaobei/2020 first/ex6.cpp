/* 

*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    while (n > 0)
    {
        cout << n << " ";
        n /= 2;
    }

    cout << endl;
    system("pause");
    return 0;
}