#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

/*
题目描述
在一个城市区域内，被划分成了n *
m个连续的区块，每个区块都拥有不同的权值，代表着其土地价值。目前，有两家开发公司，A
公司和 B 公司，希望购买这个城市区域的土地。

现在，需要将这个城市区域的所有区块分配给 A 公司和 B 公司。

然而，由于城市规划的限制，只允许将区域按横向或纵向划分成两个子区域，
而且每个子区域都必须包含一个或多个区块。
为了确保公平竞争，你需要找到一种分配方式，使得 A 公司和 B
公司各自的子区域内的土地总价值之差最小。

注意：区块不可再分。

输入描述
第一行输入两个正整数，代表 n 和 m。

接下来的 n 行，每行输出 m 个正整数。

输出描述
请输出一个整数，代表两个子区域内土地总价值之间的最小差距。
输入示例
3 3
1 2 3
2 1 3
1 2 3
输出示例
0
*/
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> grid(n,vector<int>(m,0));
    int sum=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
            sum+=grid[i][j];
        }
    }
    // 计算横向前缀和；
    vector<int> hsum(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            hsum[i]+=grid[i][j];
        }
    }
    // 计算纵向前缀和；
    vector<int> vsum(m);
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        vsum[i] += grid[j][i];
      }
    }

    // 开始划分
    int res=INT_MAX;
    int hcut=0;
    for(int i=0;i<n;i++){
        hcut+=hsum[i];
        res=min(res,abs(sum-hcut-hcut));
    }
    int vcut = 0;
    for (int i = 0; i < m; i++) {
      vcut += vsum[i];
      res = min(res, abs(sum - vcut - vcut));
    }
    cout<<res<<endl;
    return 0;
}
