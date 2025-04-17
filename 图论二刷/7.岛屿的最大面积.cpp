#include <vector>
#include <iostream>
using namespace std;
vector<vector<int>> directions={{0,1},{1,0},{0,-1},{-1,0}};
int n;
int m;
void dfs02(vector<vector<int>> &graph,int x,int y,int &area){
    if(graph[x][y]==0){
        return;
    }
    graph[x][y]=0;
    area++;
    for(int i=0;i<4;i++){
        int nextx = directions[i][0]+x;
        int nexty = directions[i][1]+y;
        if(nextx<0||nextx>=n||nexty<0||nexty>=m){
            continue;
        }
        dfs02(graph,nextx,nexty,area);
    }
}
void daoyu02(){
    cin>>n>>m;
    vector<vector<int>> graph(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>graph[i][j];
        }
    }
    int res=0;
    int area=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(graph[i][j]==1){
                area=0;
                dfs02(graph,i,j,area);//遍历他附近所有的岛屿，统统置为0
                res=max(area,res);
            }
        }
    }
    cout<<res<<endl;
}
int main(){
    daoyu02();
    return 0;
}
