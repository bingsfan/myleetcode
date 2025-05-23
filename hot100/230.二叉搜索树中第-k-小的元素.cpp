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
/* 	vector<int> vecTree230;
	void travel_230(TreeNode *node) {
		if(node == nullptr) {
			return;
		}
		travel_230(node->left);
		vecTree230.push_back(node->val);
		travel_230(node->right);
	}
	int kthSmallest(TreeNode *root, int k) {
		travel_230(root);
		return vecTree230[k - 1];
	} */
	int kthSmallest(TreeNode *root, int k) {
		stack<TreeNode *> st;
		st.push(root);
		int res = 0;
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
				k--;
				st.pop();
				top = st.top();
				res = top->val;
				st.pop();
				if(k == 0) {
					break;
				}
			}
		}
		return res;
	}
};
// @lc code=end

