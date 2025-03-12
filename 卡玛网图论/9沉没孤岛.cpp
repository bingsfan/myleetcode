#include <iostream>
#include <vector>
using namespace std;

/* 
4 5
1 1 0 0 0
1 1 0 0 0
0 0 1 0 0
0 0 0 1 1
*/
int dir[4][2]={0,1,1,0,-1,0,0,-1};
int area;
/* 
    沉没孤岛，从四条边的边界去遍历，如果遍历到岛屿，直接将已经遍历过的岛屿设为2
    然后遍历整个grid，将留下的所有1设置为0，这就把孤岛沉没了
    之后再把所有的2变成1
*/
void dfs(vector<vector<int>> &grid,vector<vector<bool>> &visited, int x, int y){
    if(visited[x][y]||grid[x][y]==0){
        return ;
    }
    visited[x][y]=true;
    grid[x][y]=2;//设置当前的节点变成2
    for (int i = 0; i < 4; i++) {
        int nextx = x + dir[i][0];
        int nexty = y + dir[i][1];
        if (nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size()) 
            continue;  // 越界了，直接跳过
        dfs(grid, visited, nextx, nexty);
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    vector<vector<bool>> visited(n, vector<bool>(m, false));

    // 从上下两个边界去遍历
    for(int i=0;i<m;i++){
        if(!visited[0][i]&&grid[0][i]==1){
            dfs(grid,visited,0,i);
        }
        if(!visited[n-1][i]&&grid[n-1][i]==1){
            dfs(grid,visited,n-1,i);
        }
    }
    // 从左右两个边界去遍历
    for(int i=0;i<n;i++){
        if(!visited[i][0]&&grid[i][0]==1){
            dfs(grid,visited,i,0);
        }
        if(!visited[i][m-1]&&grid[i][m-1]==1){
            dfs(grid,visited,i,m-1);
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1){
                grid[i][j]=0;
            }
            if(grid[i][j]==2){
                grid[i][j]=1;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
}