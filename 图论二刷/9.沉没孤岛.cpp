#include <vector>
#include <iostream>
using namespace std;
vector<vector<int>> directions={{0,1},{1,0},{0,-1},{-1,0}};
int n;
int m;
void dfs04(vector<vector<int>> &graph,int x,int y){
    if(graph[x][y]==0||graph[x][y]==2){//这一步很重要，2相当于visited数组了
        return;
    }
    graph[x][y]=2;
    for(int i=0;i<4;i++){
        int nextx = directions[i][0]+x;
        int nexty = directions[i][1]+y;
        if(nextx<0||nextx>=n||nexty<0||nexty>=m){
            continue;
        }
        dfs04(graph,nextx,nexty);
    }
}
void daoyu04(){
    // 要沉没孤岛，就先把四周的岛设置为2，然后剩下的1设置为0，2设置为1
    cin>>n>>m;
    vector<vector<int>> graph(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>graph[i][j];
        }
    }
    for(int i=0;i<n;i++){//左右边界
        if(graph[i][0]==1){
            dfs04(graph,i,0);
        }
        if(graph[i][m-1]==1){
            dfs04(graph,i,m-1);
        }
    }
    for(int i=0;i<m;i++){//上下边界
        if(graph[0][i]==1){
            dfs04(graph,0,i);
        }
        if(graph[n-1][i]==1){
            dfs04(graph,n-1,i);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(graph[i][j]==1){
                graph[i][j]=0;
            }
            if(graph[i][j]==2){
                graph[i][j]=1;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    daoyu04();
    return 0;
}