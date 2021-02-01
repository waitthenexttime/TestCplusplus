/* 
特别注意编译时格式，换行的小问题
*/


#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    int A, B;
    cin >> A >> B;
    int count = 0, sum = 0;
    for (int i = A; i <= B; i++)
    {
        printf("%5d", i);
        count++;
        sum += i;
        if (count % 5 == 0 || i == B)
        {
            cout << '\n';
        }
    }
    printf("Sum = %d", sum);
    cout << endl;
    system("pause");
    return 0;
}