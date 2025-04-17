#include <vector>
#include <iostream>
using namespace std;
vector<vector<int>> directions={{0,1},{1,0},{0,-1},{-1,0}};
int n;
int m;
void dfs03(vector<vector<int>> &graph,int x,int y){
    if(graph[x][y]==0){
        return;
    }
    graph[x][y]=0;
    for(int i=0;i<4;i++){
        int nextx = directions[i][0]+x;
        int nexty = directions[i][1]+y;
        if(nextx<0||nextx>=n||nexty<0||nexty>=m){
            continue;
        }
        dfs03(graph,nextx,nexty);
    }
}
void daoyu03(){
    // 要计算孤岛的总面积，那就从四条边开始遍历，如果有岛，将附近的岛全部置为0
    cin>>n>>m;
    vector<vector<int>> graph(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>graph[i][j];
        }
    }
    int res=0;
    for(int i=0;i<n;i++){//左右边界
        if(graph[i][0]==1){
            dfs03(graph,i,0);
        }
        if(graph[i][m-1]==1){
            dfs03(graph,i,m-1);
        }
    }
    for(int i=0;i<m;i++){//上下边界
        if(graph[0][i]==1){
            dfs03(graph,0,i);
        }
        if(graph[n-1][i]==1){
            dfs03(graph,n-1,i);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(graph[i][j]==1){
                res++;
            }
        }
    }
    cout<<res<<endl;
}
int main(){
    daoyu03();
    return 0;
}