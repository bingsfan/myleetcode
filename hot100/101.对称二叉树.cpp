/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
	bool isSame(TreeNode *t1, TreeNode *t2) {
		if(t1 == nullptr && t2 == nullptr) {
			return true;
		} else if(t1 == nullptr && t2 || t2 == nullptr && t1) {
			return false;
		} else if(t1->val != t2->val) {
			return false;
		} else {
			// 相等了，要继续比较后面的
			bool l = isSame(t1->left, t2->right);
			bool r = isSame(t1->right, t2->left);
			return l && r;
		}
		return false;
	}
	bool isSymmetric(TreeNode *root) {
		return isSame(root->left, root->right);
	}
};
// @lc code=end

