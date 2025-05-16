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
	int maxRes = INT_MIN;
	int gain(TreeNode *node) {
		if(node == nullptr) {
			return 0;
		}
		int l	= max(0, gain(node->left));
		int r	= max(0, gain(node->right));
		int res = node->val + l + r;
		maxRes	= max(res, maxRes);
		return node->val + max(l, r);
	}
	int maxPathSum(TreeNode *root) {
		gain(root);
		return maxRes;
	}
};
// @lc code=end
