/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
	TreeNode *mybuild(vector<int> &preorder, vector<int> &inorder, int pl, int pr, int il,
					  int ir) {
		if(pl > pr || il > ir) {
			return nullptr;
		}
		int rootVal	   = preorder[pl];
		TreeNode *root = new TreeNode(rootVal);
		int pivot;
		for(int i = il; i <= ir; i++) {
			if(inorder[i] == rootVal) {
				pivot = i;
				break;
			}
		}
		// 构建左子树
		int leftSize  = pivot - il;
		int rightSize = ir - pivot;
		int leftPl	  = pl + 1;
		int leftPr	  = leftPl + leftSize - 1;
		int leftIl	  = il;
		int leftIr	  = pivot - 1;
		root->left	  = mybuild(preorder, inorder, leftPl, leftPr, leftIl, leftIr);
		// 构建右子树
		int rightPl = leftPr + 1;
		int rightPr = pr;
		int rightIl = pivot + 1;
		int rightIr = ir;
		root->right = mybuild(preorder, inorder, rightPl, rightPr, rightIl, rightIr);
		return root;
	}
	TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
		return mybuild(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
	}
};
// @lc code=end

