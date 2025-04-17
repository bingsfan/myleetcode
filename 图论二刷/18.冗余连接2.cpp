#include <vector>
#include <iostream>
using namespace std;
struct DSU
{
	vector<int> parent ;
	void init(int n){
		parent.resize(n+1);
		for(int i=0;i<=n;i++){
			parent[i]=i;
		}
	}
	int find(int u){
		if(parent[u]!=u){
			parent[u]=find(parent[u]);
		}
		return parent[u];
	}
	void join(int u,int v){
		u=find(u);
		v=find(v);
		if(u!=v){
			parent[v]=u;
		}
	}
	bool isSame(int u,int v){
		u = find(u);
		v = find(v);
		return u==v;
	}
};
void solution(){
	int n,s,t;
	cin>>n;
	vector<pair<int,int>> edges;
	for(int i=0;i<n;i++){
		cin>>s>>t;
		edges.push_back(pair<int,int>(s,t));
	}
	DSU dsu;
	pair<int, int> res1, res2,res;
	vector<int> parent(n+1,0);
	// 检查一个节点是否有多个父节点,res1是第一条边，res2是第二条边
	for(auto edge:edges){
		int start = edge.first,end = edge.second;
		if(parent[end]==0){
			parent[end]=start;
		}else{
			res1={parent[end],end};
			res2=edge;
			res=res2;
		}
	}
	// 再检查是否有环
	dsu.init(n);
	for(auto edge:edges){
		int u = edge.first, v = edge.second;
		if(dsu.isSame(u,v)){
			// 说明有环了
			if(edge==res1) res=res1;
			else res=res2;
			break;
		}else{
			dsu.join(u,v);
		}
	}
	// 如果没有环就把之前的那条边输出了
	cout<<res.first<<" "<<res.second<<endl;
	return;
}
int main(int argc, char *argv[]) {
	solution();
	return 0;
}