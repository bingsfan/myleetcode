/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */

// @lc code=start
class Solution
{
  public:
    /*
    找出所有相加之和为 n 的 k 个数的组合，且满足下列条件：
    只使用数字1到9
    每个数字最多使用一次
    返回所有可能的有效组合的列表,该列表不能包含相同的组合两次，组合可以以任何顺序返回。
  */
    void traceback(int target, int k, int startIndex, int &sum, vector<int> &path, vector<vector<int>> &res)
    {
        if (sum > target)
        {
            return;
        } // 剪枝1
        if (path.size() == k)
        {
            if (sum == target)
            {
                res.push_back(path);
            }
            return;
        }
        // for (int i = startIndex; i <= 9; i++)
        // 剪枝2
        for (int i = startIndex; 9 - i + 1 >= k - path.size(); i++)
        {
            path.push_back(i);
            sum += i;
            traceback(target, k, i + 1, sum, path, res);
            path.pop_back();
            sum -= i;
        }
    }
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<int> path;
        vector<vector<int>> res;
        int sum = 0;
        traceback(n, k, 1, sum, path, res);
        return res;
    }
};
// @lc code=end
