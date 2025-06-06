/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
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
	void flatten(TreeNode *root) {
		if(root == nullptr) {
			return;
		}
		stack<TreeNode *> st;
		st.push(root);
		while(!st.empty()) {
			TreeNode *top = st.top();
			if(top != nullptr) {
				st.pop();
				if(top->right)
					st.push(top->right);
				if(top->left)
					st.push(top->left);
				st.push(top);
				st.push(nullptr);
			} else {
				st.pop();
				top = st.top();
				st.pop();
				top->left = nullptr;
				if(!st.empty()) {
					top->right = st.top();
				}
			}
		}
		return;
	}
};
// @lc code=end

