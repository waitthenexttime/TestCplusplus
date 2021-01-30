#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int F;
    cin >> F;
    int C = 5 * (F - 32) / 9;
    printf("Celsius = %d\n", C);
    system("pause");
    return 0;
}