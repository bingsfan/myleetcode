#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

/* 
    拓扑排序的步骤主要是：
    1.先统计每一个节点的入度，然后将入度为0的节点加入队列中
    2.在队列中遍历入度为0的节点，要让这些节点所指向的节点的入度也-1，如果-1后遇到了入度为0的节点，再加入队列中
*/
int main() {
    int m, n, s, t;
    cin >> n >> m;
    vector<int> inDegree(n, 0); // 记录每个文件的入度
    queue<int> que;
    unordered_map<int, vector<int>> umap;// 记录文件依赖关系
    vector<int> result; // 记录结果
    while (m--)
    {
        cin>>s>>t;
        inDegree[t]++;
        umap[s].push_back(t);
    }
    for(int i=0;i<n;i++){
        if(inDegree[i]==0){
            que.push(i);
        }
    }
    while(!que.empty()){
        int top=que.front();
        que.pop();
        result.push_back(top);
        vector<int> to=umap[top];
        if(to.size()){
            for(int i=0;i<to.size();i++){
                inDegree[to[i]]--;
                if(inDegree[to[i]]==0){
                    que.push(to[i]);
                }
            }
        }
    }
    if(result.size()==n){
        for(int i=0;i<n-1;i++){
            cout<<result[i]<<" ";
        }
        cout<<result[n-1];
    }else{
        cout<<-1<<endl;
    }
    return 0;
}