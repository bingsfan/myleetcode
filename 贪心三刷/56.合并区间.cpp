/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
class Solution
{
  public:
    /*
    合并区间，intervals的长度>=1，先处理一下边界，如果长度为1，合并个蛋直接返回就行了
    对于这种区间的问题一般都是要排序的，按照start进行排序，排序这里也有个问题啊：
    在使用sort书写表达式的时候使用const &会让排序速度加快的
    因为返回值是合并后的区间，定义个res把,因为特殊情况已经处理，现在至少都有两个区间了
    先让第一个区间进去，然后检查第二个区间和第一个区间有没有重叠，
	如果有，比较这两个的右边界谁大，取大的；没有就直接 push
    依次这样，当前遍历到的数组去和res.back()做对比
  */
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        if (intervals.size() == 1)
        {
            return intervals;
        }
        // 排序,对start从小到大排序
        sort(intervals.begin(), intervals.end(),
             [](const vector<int> &a, const vector<int> &b) { return a[0] < b[0]; });
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++)
        {
            if (res.back()[1] >= intervals[i][0])
            {
                res.back()[1] = max(intervals[i][1], res.back()[1]);
            }
            else
            {
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};
// @lc code=end
