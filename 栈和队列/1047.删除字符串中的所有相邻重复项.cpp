/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 *
 * [1047] 删除字符串中的所有相邻重复项
 */

// @lc code=start
class Solution
{
  public:
    string removeDuplicates(string s)
    {
        stack<char> st;
        string res;
        // 如果栈为空直接加入，如果不为空进行匹配，如果匹配不成功就加入栈，匹配成功就弹出并且不入栈
        // 这里注意从栈中弹出的结果需要翻转
        for (auto c : s)
        {
            if (st.empty())
            {
                st.push(c);
            }
            else
            {
                char top = st.top();
                if (top == c)
                {
                    st.pop();
                }
                else
                {
                    st.push(c);
                }
            }
        }
        while (!st.empty())
        {
            char top = st.top();
            st.pop();
            res.push_back(top);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end
