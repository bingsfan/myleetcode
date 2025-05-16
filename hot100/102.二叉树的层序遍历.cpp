/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
	vector<vector<int>> levelOrder(TreeNode *root) {
		queue<TreeNode *> q;
		vector<vector<int>> res;
		vector<int> path;
		if(root == nullptr) {
			return res;
		}
		q.push(root);
		while(!q.empty()) {
			int que_size = q.size();
			for(int i = 0; i < que_size; i++) {
				TreeNode *top = q.front();
				q.pop();
				if(top->left)
					q.push(top->left);
				if(top->right)
					q.push(top->right);
				path.push_back(top->val);
			}
			res.push_back(path);
			path.clear();
		}
		return res;
	}
};
// @lc code=end

