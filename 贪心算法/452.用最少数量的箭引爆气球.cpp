/*
 * @lc app=leetcode.cn id=452 lang=cpp
 *
 * [452] 用最少数量的箭引爆气球
 */

// @lc code=start
class Solution
{
  public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        sort(points.begin(), points.end(), [](vector<int> a, vector<int> b) { return a[0] < b[0]; });
        int res = 0;
        for (int i = 1; i < points.size(); i++)
        {
            int aright = points[i - 1][1];
            int bleft = points[i][0];
            int bright = points[i][1];
            // 如果有重合要修改当前的边界
            // 如果没一点点重合直接res+1
            if (bleft > aright)
            {
                res++;
            }
            else
            {
                points[i][1] = min(bright, aright);
            }
        }
        res += 1;
        return res;
    }
};
// @lc code=end
