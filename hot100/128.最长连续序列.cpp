/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */

// @lc code=start
class Solution {
public:
	int longestConsecutive(vector<int> &nums) {
		unordered_set<int> uset;
		for(auto &num : nums) {
			uset.insert(num);
		}
		int res = 0;
		for(auto &num : uset) {
			if(!uset.count(num - 1)) {
				int curLen = 1;
				int curNum = num;
				while(uset.count(curNum + 1)) {
					curLen++;
					curNum++;
				}
				res = max(res, curLen);
			}
		}
		return res;
	}
};
// @lc code=end

