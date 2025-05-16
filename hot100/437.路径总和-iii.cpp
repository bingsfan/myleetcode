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
	unordered_map<int64_t, int> preSum;
	int dfs(TreeNode *node, int64_t curSum, int target) {
		if(node == nullptr) {
			return 0;
		}
		curSum += node->val;
		int res = preSum[curSum - target];
		preSum[curSum]++;
		res += dfs(node->left, curSum, target);
		res += dfs(node->right, curSum, target);
		preSum[curSum]--;
		return res;
	}
	int pathSum(TreeNode *root, int targetSum) {
		preSum[0] = 1;
		return dfs(root, 0, targetSum);
	}
};
// @lc code=end

