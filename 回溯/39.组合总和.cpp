/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution
{
  public:
  /* 
  像这种可以重复使用之前的数的，在递归的时候i不变，前面几个题都是自身只能选一次，所以startIndex和i同时在变化
  因为自身和之后的元素还可以选择使用，所以i不变
  */
    void traceback3(vector<int> &candidates, int target, int &sum, int startIndex, vector<int> &path,
                    vector<vector<int>> &res)
    {
        if (sum > target)
        {
            return;
        }
        if (sum == target)
        {
            res.push_back(path);
            return;
        }
        for (int i = startIndex; i < candidates.size(); i++)
        {
            sum += candidates[i];
            path.push_back(candidates[i]);
            traceback3(candidates, target, sum, i, path, res);
            path.pop_back();
            sum -= candidates[i];
        }
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<int> path;
        vector<vector<int>> res;
        int sum = 0;
        traceback3(candidates, target, sum, 0, path, res);
        return res;
    }
};
// @lc code=end
