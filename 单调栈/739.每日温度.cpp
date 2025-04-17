/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */

// @lc code=start
class Solution
{
  public:
    /*
        先造一个结果数组，肯定和temperatures长度一样，然后初始化都为0
        用一个单调递减的栈(从栈底到栈顶)，栈顶存储着访问过的最小的元素
        如果当前遍历的元素大于栈顶，则要一直出栈，并且将结果添加到res数组中，直到当前元素小于栈顶元素位置
        如果当前遍历的元素小于栈顶直接入栈
    */
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        int n = temperatures.size();
        vector<int> res(n, 0);
        stack<pair<int, int>> stk;
        for (int i = 0; i < n; i++)
        {
            while (!stk.empty() && temperatures[i] > stk.top().first)
            {
                res[stk.top().second] = i - stk.top().second;
                stk.pop();
            }
            stk.push(pair<int, int>(temperatures[i], i));
        }
        return res;
    }
};
// @lc code=end
