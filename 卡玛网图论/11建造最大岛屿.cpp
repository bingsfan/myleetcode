#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
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
    最大岛屿问题，先求出每个岛屿的面积
    然后再看怎么加入
*/
void dfs(vector<vector<int>> &grid,vector<vector<bool>> &visited, int x, int y,int mark){
    if(visited[x][y]||grid[x][y]==0){
        return ;
    }
    visited[x][y]=true;
    area++;
    grid[x][y]=mark;
    for (int i = 0; i < 4; i++) {
        int nextx = x + dir[i][0];
        int nexty = y + dir[i][1];
        if (nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size()) 
            continue;
      
        dfs(grid, visited, nextx, nexty,mark);
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
    vector<vector<bool>> visited(n, vector<bool>(m, false)); // 标记访问过的点
    unordered_map<int ,int> gridNum;//<编号，面积>
    int mark = 2; // 记录每个岛屿的编号
    bool isAllGrid = true; // 标记是否整个地图都是陆地
    gridNum[0]=0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 0) isAllGrid = false;
            if (!visited[i][j] && grid[i][j] == 1) {
                area = 0;
                dfs(grid, visited, i, j, mark); // 将与其链接的陆地都标记上 true
                gridNum[mark] = area; // 记录每一个岛屿的面积
                mark++; // 记录下一个岛屿编号
            }
        }
    }
    if (isAllGrid) {
        cout << n * m << endl; // 如果都是陆地，返回全面积
        return 0; // 结束程序
    }
    int res=0;
    unordered_set<int> set;//标记访问过的岛屿
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==0){
                area=1;
                set.clear();
                for(int k=0;k<4;k++){
                    int nexti=i+dir[k][0];
                    int nextj=j+dir[k][1];
                    if (nexti < 0 || nexti >= grid.size() || nextj < 0 || nextj >= grid[0].size()) 
                        continue;
                    if(set.count(grid[nexti][nextj]))
                        continue;
                    set.insert(grid[nexti][nextj]);
                    area+=gridNum[grid[nexti][nextj]];
                }
            }
            res = max(res,area);
        }
    }
    cout<<res<<endl;
}