/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

// @lc code=start
class Solution {
public:
	void sortColors(vector<int> &nums) {
		int low = 0, cur = 0, high = nums.size() - 1;
		while(cur <= high) {
			if(nums[cur] == 0) {
				swap(nums[low], nums[cur]);
				low++, cur++;
			} else if(nums[cur] == 1) {
				cur++;
			} else {
				swap(nums[high], nums[cur]);
				high--;
			}
		}
	}
};
// @lc code=end

