/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
 */

// @lc code=start
class Solution
{
  public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b) { return a[0] < b[0]; });
        int res = 0;
        for (int i = 1; i < intervals.size(); i++)
        {
            int aright = intervals[i - 1][1];
            int bleft = intervals[i][0];
            int bright = intervals[i][1];
            // 如果没一点点重合直接不管
            if (bleft >= aright)
            {
                continue;
            } // 如果有重合要修改当前的边界，并且res++
            else
            {
                intervals[i][1] = min(bright, aright);
                res++;
            }
        }
        return res;
    }
};
// @lc code=end
