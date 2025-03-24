/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
class Solution
{
  public:
    void traceback4(vector<int> &candidates, int target, int &sum, int startIndex, vector<int> &path,
                    vector<vector<int>> &res, vector<bool> &used)
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
        // 这里终止条件也加上一个剪枝
        for (int i = startIndex; i < candidates.size()&&sum+candidates[i]<=target; i++)
        {
            // 这里大于0或startIndex都行，不过i本身就是从startIndex开始访问的
            if (i > 0 && candidates[i] == candidates[i - 1] && used[i - 1] == false)
            {
                continue;
            }
            sum += candidates[i];
            used[i] = true;
            path.push_back(candidates[i]);
            traceback4(candidates, target, sum, i + 1, path, res,used);
            path.pop_back();
            sum -= candidates[i];
            used[i] = false;
        }
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        // 这道题和39题的区别就在于39题数组中的数可以使用多次，这个只能使用一次，之前的代码改成i+1应该就可以了
        // 不太对，改完发现有重复，比如[1,7]和[7,1],因为数组中本身就有重复的元素，并且是无序的，我需要排个序
        // 还需要对相同的元素进行剪枝，相同的元素需要在同一层进行剪枝
        vector<int> path;
        vector<vector<int>> res;
        vector<bool> used(candidates.size(), false);
        sort(candidates.begin(), candidates.end());
        int sum = 0;
        traceback4(candidates, target, sum, 0, path, res, used);
        return res;
    }
};
// @lc code=end
