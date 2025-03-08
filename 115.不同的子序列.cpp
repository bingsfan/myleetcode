/*
 * @lc app=leetcode.cn id=115 lang=cpp
 *
 * [115] 不同的子序列
 */

// @lc code=start
class Solution {
public:
    /*
        s是更大的集合，而t是一个小集合
        即s能有几种取子序列的方法来形成t
        dp[i][j] ：s的前i个元素能有dp[i][j]种方法形成t的前j个元素
        if(s[i-1]==t[j-1])
            如果用s[i-1]和t[j-1]匹配,因为两个已经相等了就只用关心前面有多少种方法，
            s的前i-1个元素和t的j-1个元素相匹配，即dp[i-1][j-1]

            如果不用s[i-1]和t[j-1]匹配，那么就是s的前i-1个元素和t的前j个元素匹配，即dp[i-1][j]
        else 如果不相等
            那么s就应该缩短去和t去匹配
            即dp[i-1][j]
        初始化：
        dp[i][0]是有意义的，前i个元素一定可以形成一个空的子序列
        dp[0][j]都没有意义，初始化成0，因为s是大集合(所有都初始化为0试试,不太对)

        结果：
        dp[s.size][t.size]
    */
    int numDistinct(string s, string t) {
        int n1=s.size();
        int n2 = t.size();
        vector<vector<size_t>> dp(n1 + 1, vector<size_t>(n2 + 1, 0));
        for(int i=0;i<=n1;i++){
            dp[i][0]=1;
        }
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if (s[i - 1] == t[j - 1]){
                    dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
                }else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n1][n2];
    }
};
// @lc code=end

