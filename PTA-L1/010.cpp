/* 

*/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    vector<int> result = {a, b, c};
    sort(result.begin(), result.end());
    printf("%d->%d->%d", result[0], result[1], result[2]);
    cout << endl;
    system("pause");
    return 0;
}