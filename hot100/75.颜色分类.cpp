/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
		int lt = 0, gt = nums.size() - 1, cur = 0;
		while(cur <= gt) {
			if(nums[cur] == 0) {
				swap(nums[cur], nums[lt]);
				cur++, lt++;
			} else if(nums[cur] == 2) {
				swap(nums[cur], nums[gt]);
				gt--;
			} else {
				cur++;
			}
		}
		return;
	}
};
// @lc code=end

