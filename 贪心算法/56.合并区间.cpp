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
        自己写的如下,如果不用const+引用的话时间差的很多，不知道为啥
        原因如下：
        值传递的情况：每次调用比较函数时，都会对传入的两个vector对象进行一次深拷贝。
        这意味着每次比较都会复制两个vector的所有元素，时间复杂度为O(k)，其中k是vector的大小。
        如果每个vector包含m个元素，那么每次比较的时间是O(m)。对于n个元素排序，总的比较次数是O(nlog
       n)，因此总的时间复杂度变为O(m * n log n)。
        const引用传递的情况：此时传递的是vector的引用，不会发生拷贝，仅传递指针，时间复杂度为O(1)。因此，比较的时间复杂度是O(1)，
        总的排序时间复杂度仍然是O(nlog n)加上比较操作本身的O(1)时间，总体保持O(n log n)。
    */
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(),
             [](const vector<int> &a, const vector<int> &b) { return a[0] < b[0]; });
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++)
        {
            // 如果没一点点重合直接push进去res
            if (res.back()[1] < intervals[i][0])
            {
                res.push_back(intervals[i]);
            } // 如果有重合就需要合并了，加入res
            else
            {
                res.back()[1] = max(intervals[i][1], res.back()[1]);
            }
        }
        return res;
    }
};
// @lc code=end
