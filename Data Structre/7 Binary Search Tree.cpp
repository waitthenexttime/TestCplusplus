// 二叉搜索树基本结构

/* 
1.插入:本来想用个指针进行比较，最后滑到要插入位置，而文中使用的递归方法，比较简洁
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

typedef char ElementType;
typedef struct TNode *BinTree;
struct TNode
{
    ElementType Data;
    BinTree left;
    BinTree right;
};


BinTree Insert(BinTree BST, ElementType x)
{
    if (!BST)
    {
        BST = new TNode;
        BST->Data = x;
        BST->left = NULL;
        BST->right = NULL;
    }
    else
    {
        if (x < BST->Data)
        {
            BST->left = Insert(BST->left, x);
        }
        else if (x > BST->Data)
        {
            BST->right = Insert(BST->right, x);
        }
    }
    return BST;
}


BinTree Delete(BinTree BST, ElementType x)
{
    if (!BST)
    {
        cout << "û�ҵ�";
    }
    else if (x < BST->Data)
    {
        BST->left = Delete(BST->left, x);
    }
    else if (x > BST->Data)
    {
        BST->right = Delete(BST->right, x);
    }
    else if (BST->left == NULL && BST->right == NULL)
    {
        BinTree temp = BST;
        BST = NULL;
        delete temp;
    }
    return BST;
}


void PreOrderTraversal(BinTree BST)
{
    if (BST)
    {
        cout << BST->Data << " ";
        PreOrderTraversal(BST->left);
        PreOrderTraversal(BST->right);
    }
}

int main()
{
    int N;
    cin >> N;
    BinTree BST = NULL;
    for (int i = 0; i < N; i++)
    {
        BST = Insert(BST, 'A' + i);
    }
    PreOrderTraversal(BST);
    BST = Delete(BST, 'E');
    PreOrderTraversal(BST);
    cout << endl;
    system("pause");
    return 0;
}