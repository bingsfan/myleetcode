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
	// 从遍历顺序上说是前序遍历，要先在preorder中找根节点，然后去划分inorder，递归处理左右子树
	TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
		if(preorder.size() == 0) {
			return nullptr;
		}
		int rootVal	   = preorder[0];
		TreeNode *root = new TreeNode(rootVal);
		int index	   = 0;
		for(int i = 0; i < inorder.size(); i++) {
			if(inorder[i] == rootVal) {
				index = i;
				break;
			}
		}
		// 找到了划分点，先去划分中序,左闭右开区间
		vector<int> l_in(inorder.begin(), inorder.begin() + index);
		vector<int> r_in(inorder.begin() + index + 1, inorder.end());
		vector<int> l_pre(preorder.begin() + 1, preorder.begin() + 1 + l_in.size());
		vector<int> r_pre(preorder.begin() + 1 + l_in.size(), preorder.end());
		// 构建左右子树
		root->left	= buildTree(l_pre, l_in);
		root->right = buildTree(r_pre, r_in);
		return root;
	}
};
// @lc code=end

