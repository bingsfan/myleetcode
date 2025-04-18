#include <bits/stdc++.h>
using namespace std;
void bellmanFord(){
    int n,m,s,t,k;
    vector<vector<int>> graph;
    cin>>n>>m;
    while (m--)
    {
        cin>>s>>t>>k;
        graph.push_back({s,t,k});
    }
    vector<int> mindist(n+1,INT_MAX);
    int start = 1;
    int end = n;
    mindist[start]=0;
    for(int i=1;i<n;i++){
        for(auto &edge:graph){
			// 这里必须加上引用，不加的话时间会很慢
            // 这里对所有的边都进行松弛了
            int from = edge[0],to=edge[1],val=edge[2];
            if(mindist[from]!=INT_MAX&&mindist[to]>val+mindist[from]){
				mindist[to]= val + mindist[from];
			}
        }
    }
	if(mindist[end] == INT_MAX)
		cout << "unconnected" << endl;
	else
		cout << mindist[end] << endl;
}
int main(int argc, char *argv[]) {
    bellmanFord();
    return 0;
}