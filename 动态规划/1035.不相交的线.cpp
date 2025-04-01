/*
 * @lc app=leetcode.cn id=1035 lang=cpp
 *
 * [1035] 不相交的线
 */

// @lc code=start
class Solution
{
  public:
    int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2)
    {
        vector<vector<int>> dp(501, vector<int>(501, 0));
        int res = 0;
        for (int i = 1; i <= nums1.size(); i++)
        {
            for (int j = 1; j <= nums2.size(); j++)
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
