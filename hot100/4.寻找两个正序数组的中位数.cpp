/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
class Solution {
public:
	double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
		if(nums1.size() > nums2.size()) {
			swap(nums1, nums2);
		}
		int m = nums1.size(), n = nums2.size();
		int left = 0, right = m;
		while(left <= right) {
			int i = (left + right) / 2;
			int j = (m + n + 1) / 2 - i;

			int maxLeftA  = (i == 0) ? INT_MIN : nums1[i - 1];
			int minRightA = (i == m) ? INT_MAX : nums1[i];
			int maxLeftB  = (j == 0) ? INT_MIN : nums2[j - 1];
			int minRightB = (j == n) ? INT_MAX : nums2[j];

			if(maxLeftA <= minRightB && maxLeftB <= minRightA) {
				if((m + n) % 2 == 0)
					return (max(maxLeftA, maxLeftB) + min(minRightA, minRightB)) / 2.0;
				else
					return max(maxLeftA, maxLeftB);
			} else if(maxLeftA > minRightB) {
				right = i - 1;
			} else {
				left = i + 1;
			}
		}
		return 0.0;	   // 不可能到这
	}
};
// @lc code=end

