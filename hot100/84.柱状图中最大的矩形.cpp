/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

// @lc code=start
class Solution {
public:
	int largestRectangleArea(vector<int> &heights) {
		typedef pair<int, int> pli;
		heights.emplace(heights.begin(), 0);
		heights.emplace_back(0);
		int res = heights[0];
		stack<pli> st;
		for(int i = 0; i < heights.size(); i++) {
			pli now = { heights[i], i };
			while(!st.empty() && now.first < st.top().first) {
				int h = st.top().first;
				st.pop();
				if(st.empty()) {
					res = max(res, h);
					continue;
				}
				int w = i - st.top().second - 1;
				res	  = max(res, w * h);
			}
			st.emplace(now);
		}
		return res;
	}
};
// @lc code=end

