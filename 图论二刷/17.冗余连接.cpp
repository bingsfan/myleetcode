#include <vector>
#include <iostream>
using namespace std;
vector<int> parent(1001,0);
void init(int n){
	for(int i=0;i<n;i++){
		parent[i]=i;
	}
}
int find(int u){
	if(parent[u]!=u){
		parent[u]=find(parent[u]);
	}
	return parent[u];
}
// 将u->v这条边加入并查集
void join(int u,int v){
	u=find(u);
	v=find(v);
	if(u!=v){
		parent[u]=v;
	}
}
bool isSame(int u,int v){
	u = find(u);
	v = find(v);
	return u==v;
}
/*
5 4
1 2
1 3
2 4
3 4
1 4
*/
void findEdge(){
	int n,m,s,t,start,end;
	cin>>n>>m;
	init(n);
	while (m--)
	{
		cin>>s>>t;
		join(s,t);
	}
	cin>>start>>end;
	// 要判断是否存在一条start->end的路径
	if(isSame(start,end)){
		cout<<1<<endl;
	}else
	{
		cout<<0<<endl;
	}
	return ;
}
int main(int argc, char *argv[]) {
    findEdge();
    return 0;
}