#include <bits/stdc++.h>
using namespace std;
struct Edge {
	int to, value;
};

struct mycompare
{
    bool operator()(const Edge &a,const Edge &b){
        return a.value>b.value;
    }
};

void dijkstra_opt() {
	int n, m;
	cin >> n >> m;
	int s, t, k;
	// 这是个有向图
	vector<list<Edge>> graph(n + 1);
	vector<int> mindist(n + 1, INT_MAX);
	vector<int> parent(n + 1, 0);
	vector<bool> visited(n + 1, false);
	while(m--) {
		cin >> s >> t >> k;
		graph[s].push_back({ t, k });
	}
	int start = 1, end = n;
    priority_queue<Edge,vector<Edge>,mycompare> pq;
    pq.push({start,0});
	mindist[start] = 0;
	while(!pq.empty()) {
		// 找和start最近的节点
		int addNodeIndex = pq.top().to;
        pq.pop();
		visited[addNodeIndex] = true;
		for(auto edge : graph[addNodeIndex]) {
			if(!visited[edge.to] && mindist[edge.to] > mindist[addNodeIndex] + edge.value) {
				mindist[edge.to] = mindist[addNodeIndex] + edge.value;
                pq.push({ edge.to, mindist[edge.to] });
				parent[edge.to]	 = addNodeIndex;
			}
		}
	}
	if(mindist[end] == INT_MAX) {
		cout << -1 << endl;
	} else {
		cout << mindist[end] << endl;
	}
}
int main(int argc, char *argv[]) {
    dijkstra_opt();
    return 0;
}