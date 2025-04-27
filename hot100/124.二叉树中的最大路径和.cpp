/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
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
	int maxSum = INT_MIN;

	int dfs(TreeNode *node) {
		if(!node)
			return 0;

		int left  = max(0, dfs(node->left));	 // 左子树最大贡献
		int right = max(0, dfs(node->right));	 // 右子树最大贡献

		int current_max = node->val + left + right;	   // 当前节点作为拐点的路径和
		maxSum			= max(maxSum, current_max);	   // 更新全局最大

		return node->val + max(left, right);	// 返回单边路径给父节点
	}

	int maxPathSum(TreeNode *root) {
		dfs(root);
		return maxSum;
	}
};
// @lc code=end

