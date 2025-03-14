#include <iostream>
#include <vector>
#include <list>
#include <climits>
using namespace std;
/* 
6 7
5 6 -2
1 2 1
5 3 1
2 5 2
2 4 -3
4 6 4
1 3 5
*/
int main() {
    int n, m, p1, p2, val;
    cin >> n >> m;

    vector<vector<int>> grid;

    // 将所有边保存起来
    for(int i = 0; i < m; i++){
        cin >> p1 >> p2 >> val;
        // p1 指向 p2，权值为 val
        grid.push_back({p1, p2, val});

    }
    int start = 1;  // 起点
    int end = n;    // 终点

    vector<int> minDist(n+1,INT_MAX);
    minDist[start]=0;
    for(int i=1;i<n;i++){
        for(auto side:grid){
            int from=side[0];
            int to=side[1];
            int val=side[2];

            if(minDist[from]!=INT_MAX&&minDist[from]+val<minDist[to]){
                minDist[to]=minDist[from]+val;
            }
        }
    }
    if(minDist[end]==INT_MAX) cout<<"unconnected"<<endl;
    else cout<<minDist[end]<<endl;
    return 0;
}