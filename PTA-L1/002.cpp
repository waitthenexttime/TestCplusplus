/* 
1.注意剩余得不是余数，而是差值
2.循环嵌套，分别输出空格和*
*/

#include <iostream>
using namespace std;
int main()
{
    int N, rows = 1, surplus;
    char symbol;
    cin >> N >> symbol;
    while (2 * rows * rows - 1 <= N)
    {
        rows++;
    }
    rows--;
    surplus = N - (2 * rows * rows - 1);
    for (int line = 1; line <= 2 * rows - 1; line++)
    {
        for (int j = 0; j < (rows-1) - abs(rows - line); j++)
        {
            cout << " ";
        }
        for (int k = 0; k < 2 * (abs(rows - line) + 1) -1; k++)
        {
            cout << symbol;
        }
        cout << endl;
    }
    cout << surplus << endl;
    system("pause");
    return 0;
}
