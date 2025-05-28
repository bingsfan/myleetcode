/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
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
	vector<int> treeRob(TreeNode *node) {
		if(node == nullptr)
			return { 0, 0 };
		vector<int> l = treeRob(node->left);
		vector<int> r = treeRob(node->right);
		int val1	  = max(l[0], l[1]) + max(r[0], r[1]);
		int val2	  = node->val + l[0] + r[0];
		return { val1, val2 };
	}
	int rob(TreeNode *root) {
		vector<int> res = treeRob(root);
		return max(res[0], res[1]);
	}
};
// @lc code=end

