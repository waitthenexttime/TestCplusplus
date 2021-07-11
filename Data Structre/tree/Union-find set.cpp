#include <iostream>
#include <vector>
using namespace std;

typedef int ElementType;
struct Set
{
    ElementType data;
    int parent;
};

// 查找某个元素所在集合（用根结点表示）
int Find(vector<Set> &S, ElementType x)
{
    int i;
    for (i = 0; i < S.size() && S[i].data != x; i++)
    {
        ;
    }
    if (i >= S.size())
    {
        return -1;
    }
    for (; S[i].parent >= 0; i = S[i].parent)
    {
        ;
    }
    return i;
}

// 集合并操作
void Union(vector<Set> &S, ElementType x1, ElementType x2)
{
    int root1, root2;
    root1 = Find(S, x1);
    root2 = Find(S, x2);
    if (root1 != root2)
    {
        S[root2].parent = root1;
    }
}

int main()
{
    vector<Set> S(10);
    // Parent
    // -1 0 -1 0 2 -1 0 2 5 5
    for (int i = 0; i < 10; i++)
    {
        S[i].data = i + 1;
        int tmp;
        cin >> tmp;
        S[i].parent = tmp;
    }
    Union(S, 10, 5);
    for (auto it : S)
    {
        cout << it.data << " " << it.parent << endl;
    }
    system("pause");
    return 0;
}
