/*
 * @lc app=leetcode.cn id=392 lang=cpp
 *
 * [392] 判断子序列
 */

// @lc code=start
class Solution
{
  public:
  /* 
    我是定义了一个bool类型的dp数组，不过需要处理一下特殊的条件好像是，测试用例里面光处理s为空就行了
    也可以采用跟最长公共子序列差不多的解法，算出来这两个最长公共子序列的长度，看看和s的长度相等不
  */
    /* bool isSubsequence(string s, string t)
    {
        vector<vector<bool>> dp(101, vector<bool>(10001, false));
        if (s.empty())
        {
            return true;
        }
        for (int j = 0; j < t.size(); j++)
        {
            dp[0][j] = true;
        }
        for (int i = 1; i <= s.size(); i++)
        {
            for (int j = 1; j <= t.size(); j++)
            {
                if (s[i - 1] == t[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = dp[i][j - 1];
                }
            }
        }
        return dp[s.size()][t.size()];
    } */
	/* 
		直接用之前求公共子序列的代码，求出s和t的最长公共子序列的长度，看是否和s的长度相等
	*/
	bool isSubsequence(string s, string t) {
		int n1 = s.size();
		int n2 = t.size();
		vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
		int res=0;
		for(int i=1;i<=n1;i++){
			for(int j=1;j<=n2;j++){
				if(s[i-1]==t[j-1]){
					dp[i][j]=1+dp[i-1][j-1];
				}else{
					dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
				}
				if(dp[i][j]>res){
					res=dp[i][j];
				}
			}
		}
		return res==n1;
	}
};
// @lc code=end
