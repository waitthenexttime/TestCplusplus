#include <iostream>
#include <algorithm>
using namespace std;
int mon[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool isr(int n)
{
    if (n % 4 == 0 && n % 100 != 0 || n % 400 == 0)
    {
        return true;
    }
    return false;
}
int getDay(int year, int month)
{
    if (month == 2)
    {
        return 28 + isr(year);
    }
    else
    {
        return mon[month];
    }
}
int main()
{
    int sum = 0;
    int days = 0;
    for (int i = 2000; i < 2020; i++)
    {
        for (int j = 1; j <= 12; j++)
        {
            for (int k = 1; k <= getDay(i, j); k++)
            {
                int weekday = (days + 6) % 7;
                if (k == 1 || weekday == 1)
                {
                    sum += 2;
                }
                else
                {
                    sum++;
                }
                days++;
            }
        }
    }
    for (int j = 1; j <= 9; j++)
    {
        for (int k = 1; k <= getDay(2020, j); k++)
        {
            int weekday = (days + 6) % 7;
            if (k == 1 || weekday == 1)
                sum += 2;
            else
                sum++;
            days++;
        }
    }
    sum+=2;
    cout<<sum<<endl;
    system("pause");
    return 0;
}