#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/* 
    dijkstra基础版本
    和prim算法很像，都是一个个添加节点进入一个集合中
    1.找到距离目前集合最近的一个节点
    2.将这个节点添加进最短路径集合
    3.更新mindist数组，这个数组代表着节点1到j的最短路径
7 9
1 2 1
1 3 4
2 3 2
2 4 5
3 4 2
4 5 3
2 6 4
5 7 4
6 7 9
*/

int main(){
    int n,m,s,t,k;
    cin>>n>>m;
    vector<vector<int>> grid(n+1,vector<int>(n+1,INT_MAX));
    while (m--)
    {
        cin>>s>>t>>k;
        grid[s][t]=k;
    }
    int start=1;
    int end=n;
    vector<int> minDist(n+1,INT_MAX);
    vector<bool> visited(n+1,false);
    minDist[start]=0;
    for(int i=1;i<=n;i++){
        // 总共要将n个节点都加入集合，所以是n次
        int minval=INT_MAX;
        int cur=0;
        // 第一步
        for(int v=1;v<=n;v++){
            if(!visited[v]&&minDist[v]<minval){
                minval=minDist[v];
                cur=v;
            }
        }
        // 第二步
        visited[cur]=true;
        // 第三步
        for(int v=1;v<=n;v++){
            if(!visited[v]&&grid[cur][v]!=INT_MAX&&minDist[cur]+grid[cur][v]<minDist[v]){
                minDist[v]= minDist[cur]+grid[cur][v];
            }
        }
        // cout << "select:" << cur << endl;
        // for (int v = 1; v <= n; v++) cout <<  v << ":" << minDist[v] << " ";
        // cout << endl << endl;;  
    }
    
    if (minDist[end] == INT_MAX) cout << -1 << endl;
    else cout << minDist[end] << endl;
    return 0;
}