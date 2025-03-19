/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution
{
  public:
    /*
    写一个匹配的函数，(),[],{}匹配
    忘记考虑栈为空的时候加入右括号的情况了，报错了一次
    栈不为空，右括号才能去匹配
*/
    bool isPair(char a, char b)
    {
        // a为左括号
        if (a == '{' && b == '}' || a == '(' && b == ')' || a == '[' && b == ']')
        {
            return true;
        }
        return false;
    }
    bool isValid(string s)
    {
        // 左括号直接入栈，右括号匹配
        stack<char> st;
        for (auto c : s)
        {
            if (c == '(' || c == '[' || c == '{')
            {
                st.push(c);
            }
            else
            {
                if (st.empty())
                {
                    return false;
                }
                char top = st.top();
                if (isPair(top, c))
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        if (st.empty())
        {
            return true;
        }
        return false;
    }
};
// @lc code=end
