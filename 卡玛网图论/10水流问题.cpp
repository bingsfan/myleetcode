#include <iostream>
#include <vector>
using namespace std;

/* 
5 5
1 3 1 2 4
1 2 1 3 2
2 4 7 2 1
4 5 6 1 1
1 4 1 2 1
*/
int dir[4][2]={0,1,1,0,-1,0,0,-1};
int area;
/* 
    水流问题，仍然是从四条边界开始遍历，左和上代表第一组边界，右和下代表第二组边界
    要找既能到第一组边界的又能到第二组边界的，逆向从边界开始找
*/
void dfs(vector<vector<int>> &grid,vector<vector<bool>> &visited, int x, int y){
    if(visited[x][y]){
        return ;
    }
    visited[x][y]=true;
    for (int i = 0; i < 4; i++) {
        int nextx = x + dir[i][0];
        int nexty = y + dir[i][1];
        if (nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size()) 
            continue;
        if(grid[nextx][nexty]>=grid[x][y]){//下一个节点的水势应该比当前的高或相等
            dfs(grid, visited, nextx, nexty);
        }
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

    vector<vector<bool>> first(n, vector<bool>(m, false));
    vector<vector<bool>> second(n, vector<bool>(m, false));

    // 从上下两个边界去遍历
    for(int i=0;i<m;i++){
        if(!first[0][i]){
            dfs(grid,first,0,i);
        }
        if(!second[n-1][i]){
            dfs(grid,second,n-1,i);
        }
    }
    // 从左右两个边界去遍历
    for(int i=0;i<n;i++){
        if(!first[i][0]){
            dfs(grid,first,i,0);
        }
        if(!second[i][m-1]){
            dfs(grid,second,i,m-1);
        }
    }
    // 输出结果
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(first[i][j]&&second[i][j]){
                cout<<i<<" "<<j<<endl;
            }
        }
    }
}