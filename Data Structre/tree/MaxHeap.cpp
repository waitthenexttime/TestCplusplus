#include <iostream>
using namespace std;

typedef int ElementType;
typedef struct HeapStruct *MaxHeap;

struct HeapStruct
{
    ElementType *Elements;
    int Size;
    int Capacity;
};

MaxHeap Create(int MaxSize);              // 建堆
bool IsFull(MaxHeap H);                   // 判断堆是否满
bool Insert(MaxHeap H, ElementType item); // 插入元素
bool IsEmpty(MaxHeap H);                  //  判断堆是否为空
ElementType DeleteMax(MaxHeap H);         // 删除并返回堆中最大元素
void LevelOrderTraversal(MaxHeap H);      // 层序遍历

int main()
{
    MaxHeap H;
    H = Create(7);
    Insert(H, 9);
    Insert(H, 5);
    Insert(H, 6);
    Insert(H, 1);
    Insert(H, 3);
    Insert(H, 2);
    Insert(H, 4);
    LevelOrderTraversal(H);
    DeleteMax(H);
    DeleteMax(H);
    LevelOrderTraversal(H);
    system("pause");
    return 0;
}

MaxHeap Create(int MaxSize)
{
    MaxHeap H = new HeapStruct;
    H->Elements = new ElementType[MaxSize + 1];
    H->Size = 0;
    H->Capacity = MaxSize;
    // "哨兵要大于所有的可能值"
    H->Elements[0] = INT_MAX;
    return H;
}

bool IsFull(MaxHeap H)
{
    return (H->Size == H->Capacity);
}
bool IsEmpty(MaxHeap H)
{
    return !H->Size;
}
bool Insert(MaxHeap H, ElementType item)
{
    if (IsFull(H))
    {
        cout << "Heap is full" << endl;
        return false;
    }
    int i = ++H->Size;
    for (; H->Elements[i / 2] < item; i /= 2)
    {
        H->Elements[i] = H->Elements[i / 2];
    }
    H->Elements[i] = item;
    return true;
}

ElementType DeleteMax(MaxHeap H)
{
    int parent, child;
    ElementType Max, tmp;
    if (IsEmpty(H))
    {
        cout << "Heap is empty." << endl;
        return -1;
    }
    Max = H->Elements[1];
    tmp = H->Elements[H->Size--]; // 取堆最后元素
    for (parent = 1; parent * 2 <= H->Size; parent = child)
    {
        child = 2 * parent;
        // 右孩子存在且大于左孩子的值
        if ((child != H->Size) && (H->Elements[child] < H->Elements[child + 1]))
        {
            child++;
        }
        if (H->Elements[child] <= tmp)
        {
            break;
        }
        else
        {
            H->Elements[parent] = H->Elements[child];
        }
    }
    H->Elements[parent] = tmp;
    return Max;
}

void LevelOrderTraversal(MaxHeap H)
{
    for (int i = 1; i <= H->Size; i++)
    {
        printf("%d ", H->Elements[i]);
    }
    cout << endl;
}
