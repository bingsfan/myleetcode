#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;
vector<vector<int>> directions = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };
int n;
int m;
int area;
int mark;
void dfs(vector<vector<int>> &graph, vector<vector<bool>> &visited, int x, int y) {
	if(visited[x][y]||graph[x][y]==0) {
		return;
	}
	area++;
	visited[x][y] = true;
	graph[x][y]=mark;
	for(int i = 0; i < 4; i++) {
		int nextx = directions[i][0] + x;
		int nexty = directions[i][1] + y;
		if(nextx < 0 || nextx >= n || nexty < 0 || nexty >= m) {
			continue;
		}
		dfs(graph, visited, nextx, nexty);
	}
}
void daoyu() {
	cin >> n >> m;
	vector<vector<int>> graph(n, vector<int>(m, 0));
	vector<vector<bool>> visited(n, vector<bool>(m, false));
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> graph[i][j];
		}
	}
	// 先计算出每一个岛屿的面积，并且给一个编号，比如岛屿2的面积是4
	mark = 2;
	unordered_map<int, int> umap;
	// mark代表岛屿的标号，value是岛屿编号的总面积,这里把所有岛屿的面积都记录到map中了
	bool isAllLand=true;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(graph[i][j] == 1 && visited[i][j] == false) {
				area = 0;
				dfs(graph, visited, i, j);
				umap[mark++] = area;
			}
            if(graph[i][j]==0){
				isAllLand=false;
			}
		}
	}
    if(isAllLand){
		cout<<n*m<<endl;
		return;
	}
	// 现在把岛屿的面积记录在map中，并且将graph也修改了，graph[i][j]的值就是岛屿的编号
	// 如果graph[i][j]==0,这时候可以变成1，看看有没有相邻的岛屿，如果有就加上所有相邻的面积，求一个最大值
	int res=0;
	unordered_set<int> uset;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(graph[i][j]==0){
				uset.clear();
				for(int k = 0; k < 4; k++) {
					int nextx = directions[k][0] + i;
					int nexty = directions[k][1] + j;
					if(nextx < 0 || nextx >= n || nexty < 0 || nexty >= m) {
						continue;
					}
					int id = graph[nextx][nexty];
					if(id==0){//如果id==0代表这是海洋，添加它没啥必要
						continue;
					}
					if(uset.count(id)==0){
						uset.insert(id);
					}
				}
				int nearArea = 0;
				for(auto s:uset){
					nearArea+=umap[s];
				}
				res = max(res,1+nearArea);
			}
		}
	}
	cout<<res<<endl;
	return ;
}
int main(){
    daoyu();
    return 0;
}