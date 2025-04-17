#include <vector>
#include <iostream>
using namespace std;
int n;
int m;
vector<vector<int>> directions={{0,1},{1,0},{0,-1},{-1,0}};
void dfs(vector<vector<int>> &graph,vector<vector<bool>> &visited,int x,int y){
    if(visited[x][y]){
        return;
    }
    visited[x][y]=true;
    for(int i=0;i<4;i++){
        int nextx = directions[i][0]+x;
        int nexty = directions[i][1]+y;
        if(nextx<0||nextx>=n||nexty<0||nexty>=m){
            continue;
        }
        if(graph[nextx][nexty]>=graph[x][y]){
            dfs(graph,visited,nextx,nexty);
        }
    }
}
void shuiliu(){
    // 矩阵的左边界和上边界被认为是第一组边界，而矩阵的右边界和下边界被视为第二组边界。
    cin>>n>>m;
    vector<vector<int>> graph(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>graph[i][j];
        }
    }
    // 用两个visited数组，一个表示当前节点能否到第一组边界，一个表示当前节点能否到第二组边界
    vector<vector<bool>> visited_first(n,vector<bool>(m,false));
    vector<vector<bool>> visited_second(n,vector<bool>(m,false));
    for(int j=0;j<m;j++){
        // 第一行和最后一行
        dfs(graph,visited_first,0,j);
        dfs(graph,visited_second,n-1,j);
    }
    for(int i=0;i<n;i++){
        // 第一列和最后一列
        dfs(graph,visited_first,i,0);
        dfs(graph,visited_second,i,m-1);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(visited_first[i][j]&&visited_second[i][j]){
                cout<<i<<" "<<j<<endl;
            }
        }
    }
}
int main(){
    shuiliu();
    return 0;
}