/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */

// @lc code=start
class Solution {
public:
	vector<int> dailyTemperatures(vector<int> &temperatures) {
		typedef pair<int, int> temp;
		stack<temp> st;
		vector<int> res(temperatures.size(), 0);
		for(int i = 0; i < temperatures.size(); i++) {
			temp now = { temperatures[i], i };
			if(st.empty()) {
				st.push(now);
			} else {
				while(!st.empty() && st.top().first < now.first) {
					res[st.top().second] = (now.second - st.top().second);
					st.pop();
				}
				st.push(now);
			}
		}
		return res;
	}
};
// @lc code=end

