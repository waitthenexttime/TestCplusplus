/* 
初始想法，过于复杂


#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int ans = 0;
    int n1 = 0, n2 = 0, n3 = 0;
    while (ans != N)
    {
        ans++;
        n1++;
        if (n1 % 27 == 0)
        {
            n1 = 1;
            n2++;
            if (n2 % 27 == 0)
            {
                n2 = 1;
                n3++;
            }
        }
    }
    cout << char('A' + n3 - 1);
    cout << char('A' + n2 - 1);
    cout << char('A' + n1 - 1);

    cout << endl;
    system("pause");
    return 0;
}
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
    do
    {
        cout << char(64 + N % 26);
        N = N / 26;
    } while (N != 0);
    cout << endl;
    system("pause");
    return 0;
}