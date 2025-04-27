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
        // 用栈来做前序，这个题我有点迷糊，从前往后构建二叉树
		if(root == nullptr) {
			return;
		}
		stack<TreeNode *> st;
		st.push(root);
		while(!st.empty()) {
			TreeNode *cur = st.top();
			st.pop();
			if(cur->right)
				st.push(cur->right);
			if(cur->left)
				st.push(cur->left);
			if(!st.empty()) {
				cur->right = st.top();
			}
			cur->left = nullptr;
		}
	}
};
// @lc code=end

