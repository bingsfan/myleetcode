/*
 * @lc app=leetcode.cn id=491 lang=cpp
 *
 * [491] 非递减子序列
 */

// @lc code=start
class Solution
{
  public:
    vector<vector<int>> res;
    vector<int> path;
    // 这题中要学习无法排序的数组，同层如何去重
    void traceback9(vector<int> &nums, int startIndex)
    {
        // 这个不是啥都要了，得长度大于等于2
        if (path.size() >= 2)
        {
            res.push_back(path);
        }
        unordered_set<int> uset;
        for (int i = startIndex; i < nums.size(); i++)
        {
            if (!path.empty() && nums[i] < path.back() || uset.count(nums[i]))
                continue;
            uset.insert(nums[i]);
            path.push_back(nums[i]);
            traceback9(nums, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> findSubsequences(vector<int> &nums)
    {
        res.clear();
        path.clear();
        traceback9(nums, 0);
        return res;
    }
};
// @lc code=end
