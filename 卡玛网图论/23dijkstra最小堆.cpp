#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <climits>
using namespace std; 

class mycomparison {
    public:
        bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
            return lhs.second > rhs.second;
        }
};
struct Edge {
    int to;  // 邻接顶点
    int val; // 边的权重

    Edge(int t, int w): to(t), val(w) {}  // 构造函数
};

int main() {
    int n, m, s,t, k;
    cin >> n >> m;

    vector<list<Edge>> grid(n + 1);
    for(int i=0;i<m;i++){
        cin>>s>>t>>k;
        grid[s].push_back(Edge(t,k));
    }
    int start=1;
    int end=n;

    vector<int> minDist(n+1,INT_MAX);
    vector<int> visited(n+1,false);

    priority_queue<pair<int,int>,vector<pair<int,int>>,mycomparison> pq;
    pq.push(pair<int,int>(start,0));
    minDist[start]=0;

    while (!pq.empty())
    {
        // 第一步，相当于用优先级队列实现了
        pair<int,int> cur = pq.top();
        pq.pop();
        if(visited[cur.first]){
            continue;
        }
        // 第二步
        visited[cur.first]=true;
        // 第三步
        for(Edge edge:grid[cur.first]){
            if(!visited[edge.to]&&minDist[cur.first]+edge.val<minDist[edge.to]){
                minDist[edge.to]=minDist[cur.first]+edge.val;
                pq.push(pair<int,int>(edge.to,minDist[edge.to]));
            }
        }
    }
    if(minDist[end]==INT_MAX){
        cout<<-1<<endl;
    }else{
        cout<<minDist[end]<<endl;
    }
    return 0;
}
