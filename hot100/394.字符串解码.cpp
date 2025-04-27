/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] 字符串解码
 */

// @lc code=start
class Solution {
public:
	string decodeString(string s) {
		// 如果是数字，入数字栈，括号和char进符号栈,只有右括号进栈了才需要特殊处理
		// 我需要知道括号的索引
		stack<int> st_num;
		stack<char> st_c;
		string res;
		for(int i = 0; i < s.size(); i++) {
			char c = s[i];
			if(isdigit(c)) {
				// 处理多位数字
				int num = 0;
				while(i < s.size() && isdigit(s[i])) {
					num = num * 10 + (s[i] - '0');
					i++;
				}
				st_num.push(num);
				i--;	// 回退一步，因为 for 循环会再加一
			} else if(c == '[' || c == ']' || c >= 'a' && c <= 'z') {
				if(c == '[' || c >= 'a' && c <= 'z') {
					st_c.push(c);
				} else {
					string tmp = "";
					while(st_c.top() != '[') {
						tmp.insert(tmp.begin(), st_c.top());
						st_c.pop();
					}
					st_c.pop();	   // 把左括号弹出
					// 然后把tmp中的值和数字重新加入栈中
					int times = st_num.top();
					st_num.pop();
					while(times--) {
						for(auto &t : tmp) {
							st_c.push(t);
						}
					}
				}
			}
		}
		while(!st_c.empty()) {
			res += st_c.top();
			st_c.pop();
		}
		reverse(res.begin(), res.end());
		return res;
	}
};
// @lc code=end

