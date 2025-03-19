/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

// @lc code=start
class Solution
{
  public:
    int evalRPN(vector<string> &tokens)
    {
        // 如果是数字直接加入栈中，否则直接计算
        // 判断是个数字不好判断，那if就写是否是加减乘除就行了
        int res = 0;
        stack<int> st;
        for (auto s : tokens)
        {
            if (s == "+" || s == "-" || s == "*" || s == "/")
            {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                if (s == "+")
                {
                    res = a + b;
                    st.push(res);
                }
                else if (s == "-")
                {
                    res = a - b;
                    st.push(res);
                }
                else if (s == "*")
                {
                    res = a * b;
                    st.push(res);
                }
                else
                {
                    res = a / b;
                    st.push(res);
                }
            }
            else
            {
                st.push(stoi(s));
            }
        }
        return st.top();
    }
};
// @lc code=end
