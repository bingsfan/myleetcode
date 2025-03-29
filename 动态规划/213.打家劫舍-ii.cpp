/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

// @lc code=start
class Solution
{
  public:
    int rob1(vector<int> &nums)
    {
        vector<vector<int>> dp(101, vector<int>(2, 0));
        dp[0][1] = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = dp[i - 1][0] + nums[i];
        }
        return max(dp[nums.size() - 1][0], dp[nums.size() - 1][1]);
    }
    /*
        这个房间成环了，那我就把前后分开，分别处理
        就是分成两个数组，一个数组不包含头结点，一个数组不包含尾节点
        然后求两个的最大值，这样可以规避掉整体去求取头或者取尾的情况
        如果长度为1，那数组就分不开了，单独处理一下
    */
    int rob(vector<int> &nums)
    {
        if(nums.size()==1){
            return nums[0];
        }
        vector<int> nums1(nums.begin(), nums.end() - 1);
        vector<int> nums2(nums.begin() + 1, nums.end());

        int left = rob1(nums1);
        int right = rob1(nums2);
        return max(left, right);
    }
};
// @lc code=end
