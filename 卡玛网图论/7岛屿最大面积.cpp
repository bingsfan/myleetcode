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

void dfs(vector<vector<int>> &grid,vector<vector<bool>> &visited, int x, int y){
    if(visited[x][y]||grid[x][y]==0){
        return ;
    }
    visited[x][y]=true;
    area++;
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

    int result = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && grid[i][j] == 1) {
                area=0;
                dfs(grid, visited, i, j); // 将与其链接的陆地都标记上 true
                result=max(area,result);
            }
        }
    }
    cout << result << endl;
}