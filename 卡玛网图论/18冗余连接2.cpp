#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> father(1001, 0);
/*
输入一个有向图，该图由一个有着 n 个节点(节点编号 从 1 到 n)，n 条边，
请返回一条可以删除的边，使得删除该条边之后该有向图可以被当作一颗有向树。

输入描述

第一行输入一个整数 N，表示有向图中节点和边的个数。
后续 N 行，每行输入两个整数 s 和 t，代表这是 s 节点连接并指向 t 节点的单向边
3
1 2
1 3
2 3
输出描述

输出一条可以删除的边，若有多条边可以删除，请输出标准输入中最后出现的一条
*/
void init()
{
    for (int i = 1; i <= n; i++)
    {
        father[i] = i;
    }
}
int find(int u)
{
    if (u == father[u])
    {
        return u;
    }
    return father[u] = find(father[u]);
}
bool isSame(int u, int v)
{
    u = find(u);
    v = find(v);
    return u == v;
}
// 将u->v加入
void join(int u, int v)
{
    u = find(u);
    v = find(v);
    if (u == v)
        return;
    father[u] = v;
}
// 删一条边之后判断是不是树
bool isTreeAfterRemoveEdge(const vector<vector<int>> &edges, int deleteEdge)
{
    init(); // 初始化并查集
    for (int i = 0; i < n; i++)
    {
        if (i == deleteEdge)
            continue; // 要删除的就不加入
        if (isSame(edges[i][0], edges[i][1]))
        { // 构成有向环了，一定不是树
            return false;
        }
        join(edges[i][0], edges[i][1]);
    }
    return true;
}
// 在有向图里找到删除的那条边，使其变成树
void getRemoveEdge(const vector<vector<int>>& edges) {
    init(); // 初始化并查集
    for (int i = 0; i < n; i++) { // 遍历所有的边
        if (isSame(edges[i][0], edges[i][1])) { // 构成有向环了，就是要删除的边
            cout << edges[i][0] << " " << edges[i][1];
            return;
        } else {
            join(edges[i][0], edges[i][1]);
        }
    }
}
int main()
{
    int s, t;
    cin >> n;
    vector<vector<int>> edges;
    vector<int> indegree(n + 1, 0);
    // 统计入度
    for (int i = 0; i < n; i++)
    {
        cin >> s >> t;
        indegree[t]++;
        edges.push_back({s, t});
    }
    // 找度为2的边
    vector<int> vec;
    for (int i = n - 1; i >= 0; i--)
    {
        if (indegree[edges[i][1]] == 2)
        {
            vec.push_back(i);
        }
    }
    // 情况一、情况二
    if (vec.size() > 0)
    {
        // 放在vec里的边已经按照倒叙放的，所以这里就优先删vec[0]这条边
        if (isTreeAfterRemoveEdge(edges, vec[0]))
        {
            cout << edges[vec[0]][0] << " " << edges[vec[0]][1];
        }
        else
        {
            cout << edges[vec[1]][0] << " " << edges[vec[1]][1];
        }
        return 0;
    }
    // 处理情况三
    // 明确没有入度为2的情况，那么一定有有向环，找到构成环的边返回就可以了
    getRemoveEdge(edges);
    return 0;

}