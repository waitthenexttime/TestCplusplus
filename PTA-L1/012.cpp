/* 

*/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int result = pow(2, N);
    printf("2^%d = %d", N, result);
    cout << endl;
    system("pause");
    return 0;
}