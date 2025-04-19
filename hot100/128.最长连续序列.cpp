/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */

// @lc code=start
class Solution {
public:
	int longestConsecutive(vector<int> &nums) {
		// 去他妈的不能排序，操
		// [1,0,1,2]这种有重复元素的情况有问题，感觉要去个重，不然计算的时候也有问题
		unordered_set<int> uset(nums.begin(), nums.end());
		int res = 0;
		for(auto &num : uset) {
			if(!uset.count(num - 1)) {
				// 比当前元素小1的不在集合中，可以加入
				int curLen = 1;
				int curNum = num;
				// 检查该元素的后一个元素在不在集合中
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

