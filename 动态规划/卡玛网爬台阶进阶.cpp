#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
    每次至多可以爬m阶台阶，总共有n阶台阶，总共有多少种不同的方法爬到楼顶
    其实就是用1-m这么多数去填满n有多少种方法
*/
int pataijie(int n, int m)
{
    vector<int> dp(33, 0);
    dp[0] = 1;
    vector<int> nums(m, 0);
    for (int i = 0; i < m; i++)
    {
        nums[i] = i + 1;
    }
    // 这是排列，所以要先遍历背包容量
    for (int j = 0; j <= n; j++)
    {
        for (int i = 0; i < m; i++)
        {
            if (j >= nums[i])
            {
                dp[j] += dp[j - nums[i]];
            }
        }
    }
    return dp[n];
}
int main()
{
    int n,m;
    cin>>n>>m;
    int res = pataijie(n,m);
    cout<<res<<endl;
    return 0;
}
