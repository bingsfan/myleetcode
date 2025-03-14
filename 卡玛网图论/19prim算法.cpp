#include<iostream>
#include<vector>
#include <climits>

using namespace std;
/* 
    最小生成树prim算法思路（节点）
    第一步，选距离生成树最近节点
    第二步，最近节点加入生成树
    第三步，更新非生成树节点到生成树的距离（即更新minDist数组）
7 11
1 2 1
1 3 1
1 5 2
2 6 1
2 4 2
2 3 2
3 4 1
4 5 1
5 6 2
5 7 1
6 7 1
*/
int main() {
    int v,e;
    int x,y,k;
    cin>>v>>e;
    vector<vector<int>> grid(v+1,vector<int>(v+1,10001));
    while(e--){
        cin>>x>>y>>k;
        grid[x][y]=k;
        grid[y][x]=k;
    }
    vector<int> mindist(v+1,10001);
    vector<bool> isInTree(v+1,false);
    //加上初始化
    vector<int> parent(v + 1, -1);
    // 只要循环n-1次，因为要添加n-1条边
    for(int i=1;i<v;i++){
        int cur=-1;
        int minval=INT_MAX;
        // 第一步，找到距离生成树最近的节点
        for(int j=1;j<=v;j++){
            if(!isInTree[j]&&mindist[j]<minval){
                cur=j;
                minval=mindist[j];
            }
        }
        // 第二步，加入生成树
        isInTree[cur]=true;
        // 第三步，更新mindist数组
        for(int j=1;j<=v;j++){
            if(!isInTree[j]&&grid[cur][j]<mindist[j]){
                mindist[j]=grid[cur][j];
                parent[j] = cur; // 记录边
            }
        }
    }
    int res=0;
    for(int i=2;i<=v;i++){
        res+=mindist[i];
    }
    cout<<res<<endl;
    return 0;
}