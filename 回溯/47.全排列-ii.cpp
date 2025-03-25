/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
class Solution
{
  public:
    vector<vector<int>> res;
    vector<int> path;
    void traceback11(vector<int> &nums, vector<bool> &used)
    {
        if (path.size() == nums.size())
        {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (used[i])
                continue;
            if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false)
            {
                continue;
            }
            used[i] = true;
            path.push_back(nums[i]);
            traceback11(nums, used);
            path.pop_back();
            used[i] = false;
        }
    }
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        // 又是可重复，排序后同层去重
        sort(nums.begin(), nums.end());
        vector<bool> used(nums.size(), false);
        res.clear();
        path.clear();
        traceback11(nums, used);
        return res;
    }
};
// @lc code=end
