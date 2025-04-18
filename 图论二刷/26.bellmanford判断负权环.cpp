#include <bits/stdc++.h>
using namespace std;
void bellmanFord_minus(){
	int n, m, s, t, k;
	vector<vector<int>> graph;
	cin >> n >> m;
	while(m--) {
		cin >> s >> t >> k;
		graph.push_back({ s, t, k });
	}
	vector<int> mindist(n + 1, INT_MAX);
	int start = 1;
	int end	  = n;
    mindist[start]=0;
    bool flag = false;
    for(int i=1;i<=n;i++){
        for(auto &edge:graph){
            int from = edge[0],to=edge[1],val=edge[2];
            if(i<n){
				if(mindist[from] != INT_MAX && mindist[to] > val + mindist[from]) {
					mindist[to] = val + mindist[from];
				}
			}else if(i==n){
                // 如果第n次还能松弛下去，说明有负权的环了
				if(mindist[from] != INT_MAX && mindist[to] > val + mindist[from]) {
					flag = true;
				}
			}
        }
    }
    if(flag){
        cout<<"circle"<<endl;
    }else if(mindist[end]==INT_MAX){
        cout<<"unconnected"<<endl;
    }else{
		cout << mindist[end] << endl;
	}
}
int main(int argc, char *argv[]) {
    bellmanFord_minus();
    return 0;
}