/*
 * @lc app=leetcode.cn id=437 lang=cpp
 *
 * [437] 路径总和 III
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
	int dfs(TreeNode *node, uint64_t current_sum, int target,
			unordered_map<uint64_t, int> &pre_sum_count) {
		if(node == nullptr) {
			return 0;
		}
		current_sum += node->val;
		int res = pre_sum_count[current_sum - target];
		pre_sum_count[current_sum]++;
		res += dfs(node->left, current_sum, target, pre_sum_count);
		res += dfs(node->right, current_sum, target, pre_sum_count);
		pre_sum_count[current_sum]--;
		return res;
	}
	int pathSum(TreeNode *root, int targetSum) {
		unordered_map<uint64_t, int> prefix_sum_count;	  // 用于记录路径和出现的次数
		prefix_sum_count[0] = 1;					 // 初始化，路径和为0的次数为1
		return dfs(root, 0, targetSum, prefix_sum_count);
	}
};
// @lc code=end

