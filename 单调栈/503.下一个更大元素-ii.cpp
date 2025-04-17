/*
 * @lc app=leetcode.cn id=503 lang=cpp
 *
 * [503] 下一个更大元素 II
 */

// @lc code=start
class Solution
{
  public:
    /*
        直接将nums扩容两倍，后面那部分跟前面的完全一样，单调栈得遍历全部元素
        这种能用到索引的我还是喜欢栈中值和索引都存储，最后res的长度也得和最开始nums的长度保持一致
    */
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> res(2 * n, -1);
        nums.resize(n * 2);
        for (int i = n; i < n * 2; i++)
        {
            nums[i] = nums[i - n];
        }
        // <值，索引>
        stack<pair<int, int>> st;
        for (int i = 0; i < n * 2; i++)
        {
            while (!st.empty() && nums[i] > st.top().first)
            {
                res[st.top().second] = nums[i];
                st.pop();
            }
            st.push(pair<int, int>(nums[i], i));
        }
        res.resize(n);
        return res;
    }
};
// @lc code=end
