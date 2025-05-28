/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
public:
	bool isValid(string s) {
		stack<char> st;
		auto isValid = [&](char a, char b) {
			if(a == '(' && b == ')' || a == '[' && b == ']' || a == '{' && b == '}') {
				return true;
			}
			return false;
		};
		for(auto &c : s) {
			if(c == '(' || c == '[' || c == '{') {
				st.push(c);
			} else {
				if(st.empty()) {
					return false;
				} else {
					char top = st.top();
					if(isValid(top, c)) {
						st.pop();
					} else {
						return false;
					}
				}
			}
		}
		return st.empty();
	}
};
// @lc code=end

