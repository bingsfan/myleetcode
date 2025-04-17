#include <iostream>
#include <list>
#include <vector>
using namespace std;
void dfs(vector<list<int>> &graph,vector<bool> &visited,int cur){
	if(visited[cur]){
		return;
	}
	visited[cur]=true;
	for(auto next:graph[cur]){
		dfs(graph,visited,next);
	}
}
// 深搜遍历这个图，每遍历一个就加上true，如果dfs完全部都为true，那么就可以
void solution(){
	int n,m,s,t;
	cin>>n>>m;
	vector<list<int>> graph(n+1);
	vector<bool> visited(n+1,false);
	while (m--)
	{
		cin>>s>>t;
		graph[s].push_back(t);
	}
	dfs(graph,visited,1);
	for(int i=1;i<n+1;i++){
		if(visited[i]==false){
			cout<<-1<<endl;
			return ;
		}
	}
	cout<<1<<endl;
}
int main(int argc, char *argv[]) {
    solution();
    return 0;
}