/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
 */

// @lc code=start
class Solution
{
  public:
    /*
    如果有重叠，res++,将当前的右边界缩小，不能用erase，因为还有索引呢
    这题我居然写的有问题，醉了
    */
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        int res = 0;
        if (intervals.size() == 1)
        {
            return 0;
        }
        // 排序,对start从小到大排序
        sort(intervals.begin(), intervals.end(),
             [](const vector<int> &a, const vector<int> &b) { return a[0] < b[0]; });
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i - 1][1] > intervals[i][0])
            {
                res++;
                intervals[i][1] = min(intervals[i - 1][1], intervals[i][1]);
            }
        }
        return res;
    }
};
// @lc code=end
