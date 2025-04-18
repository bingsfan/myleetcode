#include <bits/stdc++.h>
using namespace std;
struct Edge
{
    int to,value;
};
void bellmanford_opt(){
    int n,m,s,t,k;
    // 只更新队列中的，即相连的，后面的不更新，因此需要使用邻接表来存储
    cin>>n>>m;
    vector<list<Edge>> graph(n+1);
    vector<int> mindist(n+1,INT_MAX);
    vector<bool> isInQueue(n+1,false);
    while (m--)
    {
        cin>>s>>t>>k;
        // 有向图
        graph[s].push_back({t,k});
    }
    queue<int> que;
    int start=1,end=n;
    que.push(start);
    mindist[start]=0;
    while (!que.empty())
    {
        // 取出队列头元素，即from,取出来之后不在队列中了，赋值false
        int from = que.front();que.pop();
        isInQueue[from]=false;
        for(auto &edge:graph[from]){
            int to = edge.to,val=edge.value;
            if(mindist[to]>val+mindist[from]){
                // 开始松弛操作,只松弛和当前节点相连的边，其他边不管
				mindist[to] = val + mindist[from];
                if(!isInQueue[to]){
                    // 如果to这个节点在que就不加入，因为已经加入过了，不在才要处理
                    que.push(to);
                    isInQueue[to]=true;
                }
			}
        }
    }
    if(mindist[end] == INT_MAX)
		cout << "unconnected" << endl;
	else
		cout << mindist[end] << endl;
}
int main(int argc, char *argv[]) {
    bellmanford_opt();
    return 0;
}