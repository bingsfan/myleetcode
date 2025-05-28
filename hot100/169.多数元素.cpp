/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
		int res = 0;
		int cnt = 0;
		for(auto &num : nums) {
			if(cnt == 0) {
				res = num;
			}
			cnt += res == num ? 1 : -1;
		}
		return res;
	}
};
// @lc code=end

