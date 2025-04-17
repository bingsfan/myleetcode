#include <iostream>
#include <list>
#include <vector>
using namespace std;

vector<vector<int>> result;
vector<int> path;
void dfs(const vector<list<int>> &graph,int cur,int end){
    if(cur==end){
        result.push_back(path);
        return;
    }
    for(auto next:graph[cur]){
        path.push_back(next);
        dfs(graph,next,end);
        path.pop_back();
    }
}
int main(int argc, char *argv[]) {
    int n,m,s,t;
    cin>>n>>m;
    vector<list<int>> graph(n+1);
    while (m--)
    {
        cin>>s>>t;
        graph[s].push_back(t);
    }
    path.push_back(1);
    dfs(graph,1,n);
	if(result.size()==0) cout<<-1<<endl;
    for(auto pa:result){
        for(int i=0;i<pa.size()-1;i++){
            cout<<pa[i]<<" ";
        }
        cout<<pa.back()<<endl;
    }
    return 0;
}