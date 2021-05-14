// 6-10 二分查找

/* 
只提供函数接口，并非完整代码
*/

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
#define NotFound 0
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode
{
    ElementType Data[MAXSIZE];
    Position Last; /* 保存线性表中最后一个元素的位置 */
};

List ReadInput(); /* 裁判实现，细节不表。元素从下标1开始存储 */
Position BinarySearch(List L, ElementType X);

int main()
{
    List L;
    ElementType X;
    Position P;

    L = ReadInput();
    scanf("%d", &X);
    P = BinarySearch(L, X);
    printf("%d\n", P);

    return 0;
}

Position BinarySearch(List L, ElementType X)
{
    int low = 1, high = L->Last;
    while (low <= high)
    {
        int center = (low + high) / 2;
        if (L->Data[center] == X)
        {
            return center;
        }
        else if (L->Data[center]<X)
        {
            low = center+1;
        }
        else
        {
            high=center-1;
        }        
    }
    return NotFound;
}