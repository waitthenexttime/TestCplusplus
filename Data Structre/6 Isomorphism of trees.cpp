//  7-3 树的同构

/* 
使用动态链表，即结点用int表示
如果T1可以通过若干次左右孩子互换就变成T2，则我们称两棵树是“同构”的
*/

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

struct TreeNode
{
    char data;
    int left;
    int right;
} T1[10], T2[10];

int CreateTree(TreeNode *T)
{
    int N;
    cin >> N;
    if (!N)
    {
        return -1;
    }

    char left, right;
    int root = 0; // 没有任何左右结点指向它的就是根结点！
    int check[10] = {0};
    for (int i = 0; i < N; i++)
    {
        cin >> T[i].data >> left >> right;
        if (left == '-')
        {
            T[i].left = -1;
        }
        else
        {
            T[i].left = left - '0';
            check[T[i].left] = 1;
        }
        if (right == '-')
        {
            T[i].right = -1;
        }
        else
        {
            T[i].right = right - '0';
            check[T[i].right] = 1;
        }
    }
    for (; root < N; root++)
    {
        if (!check[root])
        {
            break;
        }
    }
    return root;
}

bool Isomorphic(int R1, int R2)
{
    // 两二叉树都空
    if (R1 == -1 && R2 == -1)
    {
        return true;
    }
    // 一个二叉树空一个二叉树不空
    if ((R1 == -1 && R2 != -1) || (R1 != -1 && R2 == -1))
    {
        return false;
    }
    // 根结点值不同
    if (T1[R1].data != T2[R2].data)
    {
        return false;
    }
    // 都没左子树
    if (T1[R1].left == -1 && T2[R2].left == -1)
    {
        return Isomorphic(T1[R1].right, T2[R2].right);
    }
    // 不需要交换左右子树
    if (T1[R1].left != -1 && T2[R2].left != -1 && T1[T1[R1].left].data == T2[T2[R2].left].data)
    {
        return (Isomorphic(T1[R1].left, T2[R2].left) && Isomorphic(T1[R1].right, T2[R2].right));
    }
    // 需要交换左右子树
    else
    {
        return (Isomorphic(T1[R1].left, T2[R2].right) && Isomorphic(T1[R1].right, T2[R2].left));
    }
}
int main()
{
    int R1, R2;
    R1 = CreateTree(T1);
    R2 = CreateTree(T2);
    if (Isomorphic(R1, R2))
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
    cout << endl;
    system("pause");
    return 0;
}