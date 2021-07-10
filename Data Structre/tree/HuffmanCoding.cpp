/* 
结构中左右结点未设置为空，导致在先序遍历时进入空结点输出权值报错！
*/

#include <iostream>
#include <map>
#include <queue>
using namespace std;

struct TreeNode
{
    int weight;
    char ch = ' ';
    string code;
    // 要设为空，不然在遍历时会出错
    TreeNode *left = NULL;
    TreeNode *right = NULL;
};

//自定义排序规则
class mycomparison
{
public:
    bool operator()(const TreeNode *a, const TreeNode *b)
    {
        return a->weight > b->weight;
    }
};

// 构建哈夫曼树
TreeNode *Huffman(priority_queue<TreeNode *, vector<TreeNode *>, mycomparison> *H)
{
    TreeNode *T;
    int times = H->size();
    // 做times-1次合并
    for (int i = 1; i < times; i++)
    {
        T = new TreeNode;
        T->left = H->top();
        H->pop();
        T->right = H->top();
        H->pop();
        T->weight = T->left->weight + T->right->weight;
        H->push(T);
    }
    // T = H->top();
    // H->pop();
    return H->top();
}

// 改写先序遍历，输出叶子结点
void PreOrderTraversal(TreeNode *Huff)
{
    if (Huff)
    {
        if (Huff->ch != ' ')
        {
            cout << Huff->ch << "     " << Huff->weight << "        " << Huff->code << endl;
        }
        PreOrderTraversal(Huff->left);
        PreOrderTraversal(Huff->right);
    }
}

// 哈夫曼树编码
void GetCode(TreeNode *Huff, string code)
{
    if (Huff)
    {
        Huff->code = code;
        GetCode(Huff->left, code + "0");
        GetCode(Huff->right, code + "1");
    }
}

int main()
{
    string word = "abbbcccccdddddddd";
    map<char, int> Hash;
    for (auto ch : word)
    {
        if (!Hash.count(ch))
        {
            Hash.emplace(ch, 1);
        }
        else
        {
            Hash[ch]++;
        }
    }
    // 删除空格
    Hash.erase(' ');
    // 建堆
    priority_queue<TreeNode *, vector<TreeNode *>, mycomparison> MinHeap;
    int count = 0;
    for (auto i : Hash)
    {
        TreeNode *T = new TreeNode;
        T->weight = i.second;
        T->ch = i.first;
        MinHeap.push(T);
    }
    TreeNode *Tree = Huffman(&MinHeap);
    GetCode(Tree, "");
    cout << "Char  Weight   Code" << endl;
    PreOrderTraversal(Tree);
    system("pause");
    return 0;
}
