/*
 * @lc app=leetcode.cn id=452 lang=cpp
 *
 * [452] 用最少数量的箭引爆气球
 */

// @lc code=start
class Solution
{
  public:
  /* 
    至少都需要一根箭，也可以理解为最后一块区间还没处理
  */
    int findMinArrowShots(vector<vector<int>> &points)
    {
        int res = 0;
        // 排序,对start从小到大排序
        sort(points.begin(), points.end(), [](const vector<int> &a, const vector<int> &b) { return a[0] < b[0]; });
        // 如果重叠，修改边界，不重叠res++
        for (int i = 1; i < points.size(); i++)
        {
            if (points[i][0] <= points[i - 1][1])
            {
                points[i][1] = min(points[i][1], points[i - 1][1]);
            }
            else
            {
                res++;
            }
        }
        return res + 1;
    }
};
// @lc code=end
