/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 */

// @lc code=start
class Solution {
public:
	vector<int> partitionLabels(string s) {
		int l = 0, border = INT_MIN;
		vector<int> res;
		vector<int> hash(26, 0);
		for(int i = 0; i < s.size(); i++) {
			hash[s[i] - 'a'] = i;
		}
		for(int i = 0; i < s.size(); i++) {
			border = max(border, hash[s[i] - 'a']);
			if(i == border) {
				res.push_back(border - l + 1);
				l = border + 1;
			}
		}
		return res;
	}
};
// @lc code=end

