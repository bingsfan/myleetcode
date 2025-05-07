/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>> &intervals) {
		vector<vector<int>> res;
		// 需要先对intervals排序，按照第一个数字的大小排序
		sort(intervals.begin(), intervals.end(),
			 [](const vector<int> &a, const vector<int> &b) { return a[0] < b[0]; });
		res.push_back(intervals[0]);
		int n = intervals.size();
		for(int i = 1; i < n; i++) {
			if(intervals[i][0] <= res.back().back()) {
				// 合并的操作
				res.back().back() = max(intervals[i][1], res.back()[1]);
			} else {
				res.push_back(intervals[i]);
			}
		}
		return res;
	}
};
// @lc code=end

