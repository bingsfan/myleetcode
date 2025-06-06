/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
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
	int res;
	int height_543(TreeNode *node) {
		if(node == nullptr) {
			return 0;
		}
		int l = height_543(node->left);
		int r = height_543(node->right);
		res	  = max(res, l + r);
		return 1 + max(l, r);
	}
	int diameterOfBinaryTree(TreeNode *root) {
		res = 0;
		height_543(root);
		return res;
	}
};
// @lc code=end

