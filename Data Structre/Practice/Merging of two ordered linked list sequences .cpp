// 7-51 两个有序链表序列的合并

/*
合并采用的并非创建新链表赋值法
而是改变原先2链表的指针连线，从而输出合并后链表
实际上原先2列表已经混在一起了
Print(L);    1 2 3 4 5 6 8 10
Print(L1);   1 2 3 4 5 6 8 10
Print(L2);   2 3 4 5 6 8 10
*/

#include <iostream>
using namespace std;

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node
{
    ElementType Data;
    PtrToNode Next;
};
typedef PtrToNode List;

List Read();        /* 细节在此不表 */
void Print(List L); /* 细节在此不表；空链表将输出NULL */
List Merge(List L1, List L2);

int main()
{
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    L = Merge(L1, L2);
    Print(L);
    system("pause");
    return 0;
}

List Read()
{
    List L = new Node;
    List head = L;
    for (int i = 0;; i++)
    {
        int data;
        cin >> data;
        if (data == -1)
        {
            break;
        }
        else
        {
            List temp = new Node;
            temp->Data = data;
            L->Next = temp;
            L = L->Next;
        }
    }
    L->Next = NULL;
    return head->Next;
}

List Merge(List L1, List L2)
{
    List p1 = L1, p2 = L2;
    List L = new Node;
    List head = L;
    while (p1 && p2)
    {
        if (p1->Data < p2->Data)
        {
            L->Next = p1;
            p1 = p1->Next;
        }
        else
        {
            L->Next = p2;
            p2 = p2->Next;
        }
        L = L->Next;
    }
    if (p1)
    {
        L->Next = p1;
    }
    if (p2)
    {
        L->Next = p2;
    }
    return head->Next;
}

void Print(List L)
{
    if (L == NULL)
    {
        cout << "NULL";
    }
    List t = L;
    for (; t; t = t->Next)
    {
        cout << t->Data;
        if (t->Next != NULL)
        {
            cout << " ";
        }
    }
    cout << endl;
}