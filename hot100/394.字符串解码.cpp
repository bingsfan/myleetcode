/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] 字符串解码
 */

// @lc code=start
class Solution {
public:
	string decodeString(string s) {
		stack<char> st;
		stack<int> stnum;
		string res;
		for(int i = 0; i < s.size(); i++) {
			char c = s[i];
			if(isdigit(c)) {
				int num = 0;
				int j	= i;
				while(j < s.size() && isdigit(s[j])) {
					num = num * 10 + (s[j] - '0');
					j++;
				}
				i = j - 1;
				stnum.push(num);
			} else if(c == '[' || c >= 'a' && c <= 'z') {
				st.push(c);
			} else {
				string tmp = "";
				// 开始处理字符串
				while(st.top() != '[') {
					tmp.push_back(st.top());
					st.pop();
				}
				reverse(tmp.begin(), tmp.end());
				st.pop();	 // 弹出自己的[
				// 将times个tmp重新加入栈中去
				int times = stnum.top();
				stnum.pop();
				while(times--) {
					for(auto &t : tmp) {
						st.push(t);
					}
				}
			}
		}
		while(!st.empty()) {
			res.push_back(st.top());
			st.pop();
		}
		reverse(res.begin(), res.end());
		return res;
	}
};
// @lc code=end

