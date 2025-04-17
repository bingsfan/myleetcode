#include <bits/stdc++.h>
using namespace std;
struct DSU {
	vector<int> parent;
	DSU(int n) {
		parent.resize(n + 1);
		for(int i = 0; i <= n; i++) {
			parent[i] = i;
		}
	}
	int find(int u) {
		if(parent[u] != u) {
			parent[u] = find(parent[u]);
		}
		return parent[u];
	}
	void join(int u, int v) {
		u = find(u);
		v = find(v);
		if(u != v) {
			parent[v] = u;
		}
	}
	bool isSame(int u, int v) {
		u = find(u);
		v = find(v);
		return u == v;
	}
};
struct Edge
{
    int from,to,value;
};

void kruscal(){
    int n,m;
    int s,t,k;
    cin>>n>>m;
    vector<Edge> edges;
    while (m--)
    {
        cin>>s>>t>>k;
        edges.push_back({s,t,k});
    }
    sort(edges.begin(),edges.end(),[](const Edge &a,const Edge &b){
        return a.value<b.value;
    });
    vector<Edge> res;
    DSU dsu(n+1);
    for(auto edge:edges){
        if(dsu.isSame(edge.from,edge.to)){
            continue;
        }else{
            dsu.join(edge.from,edge.to);
            res.push_back(edge);
        }
    }
    int result = 0;
    for(auto re:res){
        result+=re.value;
    }
    cout<<result<<endl;
}
int main(int argc, char *argv[]) {
    kruscal();
    return 0;
}