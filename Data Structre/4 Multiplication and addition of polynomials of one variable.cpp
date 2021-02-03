// 7-2 一元多项式的乘法与加法运算

/* 
头结点不用可有效避免判断head==null的情况
乘法中用加法函数可以检查元素中是否有指数相同合并的情况
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct Node *List;
struct Node
{
    List Next;
    int z; //指数
    int x; //系数
};

// 读取链表
List Read()
{
    List L = new Node;
    List head = L;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int z;
        int x;
        List temp = new Node;
        cin >> x >> z;
        temp->x = x;
        temp->z = z;
        L->Next = temp;
        L = L->Next;
    }
    L->Next = NULL;
    return head->Next;
}

// 加法运算
List Addition(List L1, List L2)
{
    List p1 = L1;
    List p2 = L2;
    List add = new Node;
    add->Next = NULL;
    List head = add;
    List temp;
    while (p1 && p2)
    {
        temp = new Node;
        if (p1->z == p2->z)
        {
            temp->z = p1->z;
            temp->x = p1->x + p2->x;
            p1 = p1->Next;
            p2 = p2->Next;
        }
        else if (p1->z > p2->z)
        {
            temp->z = p1->z;
            temp->x = p1->x;
            p1 = p1->Next;
        }
        else if (p1->z < p2->z)
        {
            temp->z = p2->z;
            temp->x = p2->x;
            p2 = p2->Next;
        }
        add->Next = temp;
        add = add->Next;
    }
    if (p1)
    {
        add->Next = p1;
        p1 = p1->Next;
        add = add->Next;
    }
    if (p2)
    {
        add->Next = p2;
        p2 = p2->Next;
        add = add->Next;
    }
    return head->Next;
}

// 实现乘法运算
List Multiplication(List L1, List L2)
{
    List p1 = L1;
    List p2 = L2;
    List head = NULL;
    List temp;
    for (; p1; p1 = p1->Next)
    {
        for (p2 = L2; p2; p2 = p2->Next)
        {
            temp = new Node;
            temp->x = p1->x * p2->x;
            temp->z = p1->z + p2->z;
            temp->Next = NULL;
            head = Addition(temp, head);
        }
    }
    return head;
}

void Print(List L)
{
    List t = L;
    int flag = 1;
    for (; t; t = t->Next)
    {
        if (!flag && t->x) //控制空格输出
            printf(" ");
        if (t->x)
        { // 如果系数为 0，不输出
            printf("%d %d", t->x, t->z);
            flag = 0;
        }
    }
    if (flag)
        printf("0 0");
    printf("\n");
}

int main()
{
    List L1, L2, add, mul;
    L1 = Read();
    L2 = Read();
    add = Addition(L1, L2);
    mul = Multiplication(L1, L2);
    Print(mul);
    Print(add);
    system("pause");
    return 0;
}