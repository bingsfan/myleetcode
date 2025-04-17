#include <bits/stdc++.h>
using namespace std;
struct Edge
{
    int to,value;
    // 起点，终点和权重
};
struct mycompare
{
    bool operator()(const Edge &a,const Edge &b){
        return a.value>b.value;
    }
};

void prim_opt(){
	int n, m;
	int s, t, k;
	cin >> n >> m;
	vector<int> path;
	vector<list<Edge>> graph(n + 1);
    priority_queue<Edge,vector<Edge>,mycompare> pq;
	while(m--) {
		// 最小生成树是个无向图，一定要两边都加上
		cin >> s >> t >> k;
		graph[s].push_back({ t, k });
		graph[t].push_back({ s, k });
	}
	vector<int> mindist(n + 1, INT_MAX);
	vector<bool> visited(n + 1, false);
	vector<int> parent(n + 1, -1);
	mindist[1] = 0;
    pq.push({1,0});
    while (!pq.empty())
    {
        int start = pq.top().to;
        pq.pop();
        if(visited[start]){
            continue;
        }
        visited[start]=true;
        for(auto edge:graph[start]){
            if(!visited[edge.to]&&mindist[edge.to]>edge.value){
				mindist[edge.to] = edge.value;
                parent[edge.to]=start;
                pq.push(edge);
			}
        }
    }
	int res=0;
	for(int i = 1; i <= n; i++) {
		res += mindist[i];
	}
	cout << res << endl;
}
int main(int argc, char *argv[]) {
    prim_opt();
    return 0;
}