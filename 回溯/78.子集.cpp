/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution
{
  public:
    vector<vector<int>> res;
    vector<int> path;
    void traceback7(vector<int> &nums, int startIndex)
    {
        // 好像不要终止条件都行，直接遍历完
        res.push_back(path);
        for (int i = startIndex; i < nums.size(); i++)
        {
            path.push_back(nums[i]);
            traceback7(nums, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {
        res.clear();
        path.clear();
        traceback7(nums, 0);
        return res;
    }
};
// @lc code=end
