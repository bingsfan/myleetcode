/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
class Solution
{
  public:
    /*
  给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。
  示例: 输入: n = 4, k = 2 输出: [ [2,4], [3,4], [2,3], [1,2], [1,3], [1,4], ]
  */
    void traceback(int n, int k, int startIndex, vector<int> &path, vector<vector<int>> &res)
    {
        if (path.size() == k)
        {
            res.push_back(path);
            return;
        }
        // for (int i = startIndex; i <= n; i++)
        // 这里剪枝优化，已经选了path.size()个，还要k-path.size()个
        // i的位置还没有选，是开始位置，因此还剩下可以选择的个数为n-i+1个
        // 剩下的应该大于等于还要的
        for (int i = startIndex; n - i + 1 >= k - path.size(); i++)
        {
            path.push_back(i);
            traceback(n, k, i + 1, path, res);
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k)
    {
        vector<int> path;
        vector<vector<int>> res;
        traceback(n, k, 1, path, res);
        return res;
    }
};
// @lc code=end
