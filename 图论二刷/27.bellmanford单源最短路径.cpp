#include <bits/stdc++.h>
using namespace std;
void bellmanford_p2p(){
	int n, m, s, t, v;
	vector<vector<int>> graph;
	cin >> n >> m;
	while(m--) {
		cin >> s >> t >> v;
		graph.push_back({ s, t, v });
	}
	vector<int> mindist(n + 1, INT_MAX);
    int start,end,k;
    cin>>start>>end>>k;
    // 标准的bellmanFord算法有n个节点，需要松弛n-1次，这个最多经过k个节点，总共有k+2个节点，松弛k+1次
    mindist[start]=0;
    vector<int> mindist_cpy(n+1);
    for(int i=1;i<=k+1;i++){
		mindist_cpy=mindist;
		for(auto &edge:graph){
			int from = edge[0], to = edge[1], val = edge[2];
			if(mindist_cpy[from] != INT_MAX && mindist[to] > val + mindist_cpy[from]) {
				mindist[to] = val + mindist_cpy[from];
			}
		}
    }
    if(mindist[end]==INT_MAX){
		cout << "unreachable"<<endl;
	}else{
        cout<<mindist[end]<<endl;
    }
}
int main(int argc, char *argv[]) {
    bellmanford_p2p();
    return 0;
}