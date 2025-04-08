/*
 * @lc app=leetcode.cn id=516 lang=cpp
 *
 * [516] 最长回文子序列
 */

// @lc code=start
class Solution
{
  public:
	/*
		要求最长回文子序列的长度，dp[i][j]代表[i,j]区间内的最大回文子序列长度为dp[i][j]
		如果s[i]==s[j]，dp[i][j]=dp[i+1][j-1]+2
		否则，dp[i][j]=max(dp[i+1][j],dp[i][j-1])
		i要从后往前遍历，返回值为dp[0][n-1]
	*/
	int longestPalindromeSubseq(string s)
	{
		int n = s.size();
		vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
		for (int i = 0; i < n; i++)
		{
			dp[i][i] = i;
		}
		for (int i = n - 2; i >= 0; i--)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (s[i] == s[j])
				{
					dp[i][j] = dp[i + 1][j - 1] + 2;
				}
				else
				{
					dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
				}
			}
		}
		return dp[0][n - 1];
	}
};
// @lc code=end
