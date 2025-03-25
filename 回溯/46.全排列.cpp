/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution
{
  public:
    vector<vector<int>> res;
    vector<int> path;
    void traceback10(vector<int> &nums, vector<bool> &used)
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
            used[i] = true;
            path.push_back(nums[i]);
            traceback10(nums, used);
            path.pop_back();
            used[i] = false;
        }
    }
    // 0046.全排列
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<bool> used(nums.size(), false);
        res.clear();
        path.clear();
        traceback10(nums, used);
        return res;
    }
};
// @lc code=end
