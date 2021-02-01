/* 
find用在结构体要重写
*/


#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

struct Student
{
    string admission_number;
    string num1;
    string num2;
};

int main()
{
    int N;
    cin >> N;
    Student student;
    vector<Student> vec;
    for (int i = 0; i < N; i++)
    {
        cin >> student.admission_number >> student.num1 >> student.num2;
        vec.push_back(student);
    }
    int M;
    cin >> M;
    string num;
    vector<string> vecint;
    for (int i = 0; i < M; i++)
    {
        cin >> num;
        vecint.push_back(num);
    }
    for (string it2 : vecint)
    {
        for (Student it1 : vec)
        {
            if (it1.num1 == it2)
            {
                cout << it1.admission_number << " " << it1.num2 << endl;
            }
        }
    }

    system("pause");
    return 0;
}