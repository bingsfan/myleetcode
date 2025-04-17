#include <bits/stdc++.h>
using namespace std;
void tuopu(){
    int n,m;
    cin>>n>>m;
    int s,t;
    // 很明显这是个有向图
    vector<list<int>> graph(n);
    // 用一个入度数组
    vector<int> indegree(n);
    while (m--)
    {
        cin>>s>>t;
        graph[s].push_back(t);
        indegree[t]++;
    }
    queue<int> que;
    vector<int> res;
    // 存储入度为0的节点
    for(int i=0;i<n;i++){
        if(indegree[i]==0){
            que.push(i);
        }
    }
    while (!que.empty())
    {
        int top = que.front();que.pop();
        res.push_back(top);
        for(auto to:graph[top]){
            indegree[to]--;
            if(indegree[to]==0){
                que.push(to);
            }
        }
    }
    if(res.size()==n){
		for(int i = 0; i < res.size() - 1; i++) {
			cout << res[i] << " ";
		}
		cout << res.back();
	}else{
        cout<<-1<<endl;
    }
}
int main(int argc, char *argv[]) {
    tuopu();
    return 0;
}