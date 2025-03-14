#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/* 
    使用并查集，克鲁斯卡尔算法生成最小生成树
    先对边的权值进行排序
    然后从小到大，如果x->y中的x和y不在一个集合中就加入
    在就不管了
7 11
1 2 1
1 3 1
1 5 2
2 6 1
2 4 2
2 3 2
3 4 1
4 5 1
5 6 2
5 7 1
6 7 1
*/
// l,r为 边两边的节点，val为边的数值
struct Edge {
    int l, r, val;
};
// 节点数量
int n = 10001;
// 并查集标记节点关系的数组
vector<int> father(n, -1); // 节点编号是从1开始的，n要大一些

// 并查集初始化
void init() {
    for (int i = 0; i < n; ++i) {
        father[i] = i;
    }
}

// 并查集的查找操作
int find(int u) {
    return u == father[u] ? u : father[u] = find(father[u]); // 路径压缩
}

// 并查集的加入集合
void join(int u, int v) {
    u = find(u); // 寻找u的根
    v = find(v); // 寻找v的根
    if (u == v) return ; // 如果发现根相同，则说明在一个集合，不用两个节点相连直接返回
    father[v] = u;
}
int main() {
    int v,e;
    int x,y,k;
    int res=0;
    vector<Edge> edges;
    cin>>v>>e;
    while (e--)
    {
        cin>>x>>y>>k;
        edges.push_back({x,y,k});
    }
    // 对边的权值进行从小到大排序
    sort(edges.begin(),edges.end(),[](Edge &a,Edge &b){
        return a.val<b.val;
    });
    init();
    vector<Edge> result; // 存储最小生成树的边
    for(auto edge:edges){
        int x=find(edge.l);
        int y=find(edge.r);
        if(x!=y){
            res+=edge.val;
            result.push_back(edge); // 记录最小生成树的边
            join(x,y);
        }
    }
    // 打印最小生成树的边
    for (Edge edge : result) {
        cout << edge.l << " -> " << edge.r << " : " << edge.val << endl;
    }
    cout<<res<<endl;
    return 0;
}
