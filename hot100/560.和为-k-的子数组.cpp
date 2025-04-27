/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为 K 的子数组
 */

// @lc code=start
class Solution {
public:
	int subarraySum(vector<int> &nums, int k) {
		// 要用前缀和解决，我先求出前缀和把，用map存储，前缀和及其频率
		unordered_map<int, int> umap;
		int sum = 0;
		umap[0] = 1;
		// 意思是前缀和为0的出现了一次，因为这代表着sum==k了
		int res = 0;
		int preSum;
		for(auto &num : nums) {
			sum += num;
			preSum = sum - k;
			if(umap.count(preSum)) {
				res += umap[preSum];
			}
			umap[sum]++;
		}
		return res;
	}
};
// @lc code=end

