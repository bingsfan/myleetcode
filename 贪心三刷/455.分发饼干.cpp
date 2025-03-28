/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */

// @lc code=start
class Solution
{
  public:
    /*
    对饼干和孩子从小到大排序，想的是胃口大的先吃尺寸大的
  */
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int sIndex = s.size() - 1;
        int res = 0;
        for (int i = g.size() - 1; i >= 0 && sIndex >= 0; i--)
        {
            if (g[i] <= s[sIndex])
            {
                sIndex--;
                res++;
            }
        }
        return res;
    }
};
// @lc code=end
