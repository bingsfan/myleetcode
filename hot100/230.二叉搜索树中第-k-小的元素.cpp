/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第 K 小的元素
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
	// 二叉搜索树中第k小的元素，中序遍历转成数组然后直接返回索引就完了
	vector<int> nums;
	void travel(TreeNode *node) {
		if(node == nullptr) {
			return;
		}
		travel(node->left);
		nums.push_back(node->val);
		travel(node->right);
	}
	int kthSmallest(TreeNode *root, int k) {
		travel(root);
		return nums[k - 1];
	}
};
// @lc code=end

