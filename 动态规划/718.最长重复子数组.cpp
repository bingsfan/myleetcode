/*
 * @lc app=leetcode.cn id=718 lang=cpp
 *
 * [718] 最长重复子数组
 */

// @lc code=start
class Solution
{
  public:
    // 这样写没啥问题，但是就多了一个判断，递推公式是dp[i][j] = 1 + dp[i - 1][j - 1];
    // 我这种解法dp[i][j]代表着以nums1[i],nums2[j]为结尾的最大长度
    // 但是dp[i - 1][j - 1];需要i，j大于0，也可以判断i-1和j-1就行
    // 这时候dp数组的含义是以nums1[i-1],nums2[j-1]为结尾的最大长度
    int findLength(vector<int> &nums1, vector<int> &nums2)
    {
        vector<vector<int>> dp(1001, vector<int>(1001, 0));
        int res = 0;
        for (int i = 0; i < nums1.size(); i++)
        {
            for (int j = 0; j < nums2.size(); j++)
            {
                if (nums1[i] == nums2[j])
                {
                    if (i > 0 && j > 0)
                    {
                        dp[i][j] = 1 + dp[i - 1][j - 1];
                    }
                    else
                    {
                        dp[i][j] = 1;
                    }
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
