/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
/* 	vector<int> vecTree;
	void travel_98(TreeNode *node) {
		if(node == nullptr) {
			return;
		}
		travel_98(node->left);
		vecTree.push_back(node->val);
		travel_98(node->right);
	}
	bool isValidBST(TreeNode *root) {
		travel_98(root);
		for(int i = 1; i < vecTree.size(); i++) {
			if(vecTree[i] <= vecTree[i - 1]) {
				return false;
			}
		}
		return true;
	} */
	bool isValidBST(TreeNode *root) {
		if(root == nullptr) {
			return true;
		}
		stack<TreeNode *> st;
		st.push(root);
		int64_t prev = static_cast<int64_t> INT_MIN - 1;
		while(!st.empty()) {
			TreeNode *top = st.top();
			if(top) {
				st.pop();
				if(top->right)
					st.push(top->right);
				st.push(top);
				st.push(nullptr);
				if(top->left)
					st.push(top->left);
			} else {
				st.pop();
				top = st.top();
				if(top->val <= prev) {
					return false;
				}
				prev = top->val;
				st.pop();
			}
		}
		return true;
	}
};
// @lc code=end

