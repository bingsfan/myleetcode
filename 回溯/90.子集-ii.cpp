/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */

// @lc code=start
class Solution
{
  public:
    vector<vector<int>> res;
    vector<int> path;
    void traceback8(vector<int> &nums, int startIndex)
    {
        // 好像不要终止条件都行，直接遍历完
        res.push_back(path);
        for (int i = startIndex; i < nums.size(); i++)
        {
            if (i > startIndex && nums[i] == nums[i - 1])
            {
                continue;
            }
            path.push_back(nums[i]);
            traceback8(nums, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        // 不出意外需要对同一层进行去重，我先不用used数组试试
        res.clear();
        path.clear();
        sort(nums.begin(), nums.end());
        traceback8(nums, 0);
        return res;
    }
};
// @lc code=end
