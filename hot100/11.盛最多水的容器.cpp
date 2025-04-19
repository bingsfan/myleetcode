/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution {
public:
	int maxArea(vector<int> &height) {
		// 暴力解法来一下,暴力解法超时了，时间复杂度是n平方
		int n	= height.size();
		int res = 0;
		// 使用双指针，如果哪个矮，计算完面积就移动，滚蛋，不要他
		int left = 0, right = n - 1;
		while(left < right) {
			int area = min(height[left], height[right]) * (right - left);
			res		 = max(res, area);
			if(height[left] < height[right]) {
				left++;
			} else {
				right--;
			}
		}
		return res;
	}
};
// @lc code=end

