/*
 * @lc app=leetcode.cn id=1035 lang=cpp
 *
 * [1035] 不相交的线
 */

// @lc code=start
class Solution
{
  public:
    /*
    实质上是求两个数组的公共子序列，和上面那道题很像
    定义dp[i][j]：nums1以i-1为结尾的子序列和nums2以j-1为结尾的子序列，这两个公共子序列的长度
    要求的其实是dp[i][j]的最大值，初始化统一为0
*/
    int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2)
    {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
        int res = 0;
        for (int i = 1; i <= n1; i++)
        {
            for (int j = 1; j <= n2; j++)
            {
                if (nums1[i - 1] == nums2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
                if (dp[i][j] > res)
                {
                    res = dp[i][j];
                }
            }
        }
        return res;
    }
};
// @lc code=end
