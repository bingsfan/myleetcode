#include <bits/stdc++.h>
using namespace std;
struct Edge {
	int to, value;
};

void dijkstra() {
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
    int start =1,end= n;
    mindist[start]=0;
    for(int j=1;j<=n;j++)
    {
        // 找和start最近的节点
        int addNodeIndex=0;
        int minval = INT_MAX;
        for(int i=1;i<=n;i++){
            if(!visited[i]&&mindist[i]<minval){
                minval=mindist[i];
                addNodeIndex=i;
            }
        }
        visited[addNodeIndex]=true;
        for(auto edge:graph[addNodeIndex]){
			if(!visited[edge.to] && mindist[edge.to] > mindist[addNodeIndex] + edge.value) {
				mindist[edge.to] = mindist[addNodeIndex] + edge.value;
				parent[edge.to]=addNodeIndex;
			}
		}
    }
    if(mindist[end]==INT_MAX){
        cout<<-1<<endl;
    }else{
		cout << mindist[end] << endl;
	}
}
int main(int argc, char *argv[]) {
    dijkstra();
    return 0;
}