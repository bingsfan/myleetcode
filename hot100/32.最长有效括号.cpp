/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */

// @lc code=start
class Solution {
public:
	int longestValidParentheses(string s) {
		// 栈顶存的是“上一个没有配对的右括号的位置”,也代表子串的开始位置的前一个元素
		int res = 0;
		stack<int> st;
		st.push(-1);
		for(int i = 0; i < s.size(); i++) {
			if(s[i] == '(') {
				st.push(i);
			} else {
				st.pop();
				if(st.empty()) {
					// 说明这个右括号无法匹配，把它当成新的起点的前一位
					st.push(i);
				} else {
					// 说明匹配成功，计算有效的长度
					int len = i - st.top();
					res		= max(len, res);
				}
			}
		}
		return res;
	}
};
// @lc code=end

