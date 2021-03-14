/* 
dfs这里简单的用递归实现，正规写法需要用栈结构
*/

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define MaxVertex 100
int G[MaxVertex][MaxVertex];
int edgeNum, vertexNum;
bool visit[MaxVertex];

void Build()
{
    cin >> vertexNum;
    for (int i = 0; i < vertexNum; i++)
    {
        for (int j = 0; j < vertexNum; j++)
        {
            G[i][j] = 0;
        }
    }
    cin >> edgeNum;
    for (int i = 0; i < edgeNum; i++)
    {
        int a, b;
        cin >> a >> b;
        G[a][b] = 1;
        G[b][a] = 1;
    }
}

void DFS(int v)
{
    visit[v] = true;
    cout << " " << v;
    for (int i = 0; i < vertexNum; i++)
    {
        if (G[v][i] && !visit[i])
        {
            DFS(i);
        }
    }
}

void BFS(int v)
{
    queue<int> q;
    visit[v] = true;
    cout<<" "<<v;
    q.push(v);
    while (!q.empty())
    {
        int tmp = q.front();
        q.pop();
        for (int i = 0; i < vertexNum; i++)
        {
            if (G[tmp][i]&&!visit[i])
            {
                    visit[i]=true;
                    cout<<" "<<i;
                    q.push(i);
            }
            
        }
        
    }
    
}

int main()
{
    Build();
    // DFS
    for (int i = 0; i < vertexNum; i++)
    {
        if (visit[i] == false)
        {
            cout << "{";
            DFS(i);
            cout << " }" << endl;
        }
    }

    for (int i = 0; i < vertexNum; i++)
    {
        visit[i] = false;
    }

    // BFS
    for (int i = 0; i < vertexNum; i++)
    {
        if (visit[i] == false)
        {
            cout << "{";
            BFS(i);
            cout << " }" << endl;
        }
    }

    system("pause");
    return 0;
}