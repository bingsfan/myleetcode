/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

// @lc code=start
class Solution {
public:
	bool searchMatrix(vector<vector<int>> &matrix, int target) {
		// 用两次二分查找，第一次查找行，第二次查找列
		int n = matrix.size(), m = matrix[0].size();
		vector<int> rows;
		for(int i = 0; i < n; i++) {
			rows.push_back(matrix[i][0]);
		}
		// 要找target<=rows的位置。
		int l = 0, r = n - 1;
		int ans1 = 0;
		while(l <= r) {
			int mid = (l + r) / 2;
			if(rows[mid] <= target) {
				ans1 = mid;
				l	 = mid + 1;
			} else {
				r = mid - 1;
			}
		}
		// ans1代表从第几行开始找，下面是正经二分查找，上面是查找下界的
		l = 0, r = m - 1;
		while(l <= r) {
			int mid = (l + r) / 2;
			if(matrix[ans1][mid] > target) {
				r = mid - 1;
			} else if(matrix[ans1][mid] < target) {
				l = mid + 1;
			} else {
				return true;
			}
		}
		return false;
	}
};
// @lc code=end

