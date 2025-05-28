/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

// @lc code=start
class Solution {
public:
	bool searchMatrix(vector<vector<int>> &matrix, int target) {
		// 先在第一列里面找上界，然后再在行里面找有没有
		int m = matrix.size(), n = matrix[0].size();
		vector<int> nums;
		for(int i = 0; i < m; i++) {
			nums.push_back(matrix[i][0]);
		}
		// 要找小于等于target的第一个元素
		int l = 0, r = m - 1;
		while(l <= r) {
			int mid = (l + r) / 2;
			if(nums[mid] > target) {
				r = (r == mid) ? mid - 1 : mid;
			} else {
				l = mid + 1;
			}
		}
		int row = r;
		if(row == -1)
			return false;
		l = 0, r = n - 1;
		while(l <= r) {
			int mid = (l + r) / 2;
			if(matrix[row][mid] == target) {
				return true;
			} else if(matrix[row][mid] > target) {
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
		return false;
	}
};
// @lc code=end

