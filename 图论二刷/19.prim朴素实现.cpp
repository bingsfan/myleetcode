#include <bits/stdc++.h>
using namespace std;
struct Edge
{
    int to,value;
    // 起点，终点和权重
};

void prim(){
    int n,m;
    int s,t,k;
    cin>>n>>m;
    vector<int> path;
    vector<list<Edge>> graph(n+1);
    while (m--)
    {
        // 最小生成树是个无向图，一定要两边都加上
        cin>>s>>t>>k;
        graph[s].push_back({t,k});
        graph[t].push_back({s,k});
    }
    vector<int> mindist(n+1,INT_MAX);
    vector<bool> visited(n+1,false);
    vector<int> parent(n+1,-1);
    mindist[1]=0;
    for(int cnt=1;cnt<n;cnt++){
        int minval=INT_MAX;
        int addNodeIndex = 0;
        for(int i=1;i<=n;i++){
            // 遍历每一个节点，找距离当前构建的树的最短距离
            if(!visited[i]&&mindist[i]<minval){
                minval=mindist[i];
                addNodeIndex=i;
            }
        }
        // 将addnode这个节点加入visited数组中
        visited[addNodeIndex]=true;
        // 更新mindist数组
        for(auto edge:graph[addNodeIndex]){
            if(!visited[edge.to]&&mindist[edge.to]>edge.value){
                mindist[edge.to]=edge.value;
                parent[edge.to]=addNodeIndex;
            }
        }
    }
    int res=0;
    for(int i=1;i<=n;i++){
        res+=mindist[i];
    }
    cout<<res<<endl;
}
int main(int argc, char *argv[]) {
    prim();
    return 0;
}