#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int main()
{
    int energy = 10000;
    int t = 0;
    while (energy)
    {
        if (energy > 600)
        {
            t += 120;
            energy -= 300;
        }
        else
        {
            t += energy * 0.1;
            energy=0;
        }
    }
    cout << t;
    cout << endl;

    system("pause");
    return 0;
}