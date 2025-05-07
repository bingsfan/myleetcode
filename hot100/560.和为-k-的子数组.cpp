/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为 K 的子数组
 */

// @lc code=start
class Solution {
public:
	int subarraySum(vector<int> &nums, int k) {
		// 用unordered_map来存储到当前元素之前的前缀和和频率
		int n = nums.size();
		unordered_map<int, int> umap_sum;
		umap_sum[0] = 1;
		// !这是为了解决如果有一个元素的值恰好等于k 的情况
		int curSum = 0;
		int res	   = 0;
		for(int i = 0; i < n; i++) {
			curSum += nums[i];
			// !注意这里是cursum-k，cursum会不断变大
			// 可以想成，总长为cursum，如果要有一个和为k的子数组，我需要另一个更小的前缀和，也就是curSum-k，定义为presum
			int presum = curSum - k;
			if(umap_sum.count(presum)) {
				res += umap_sum[presum];
			}
			umap_sum[curSum]++;
		}
		return res;
	}
};
// @lc code=end

