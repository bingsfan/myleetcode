/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
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
	vector<int> rightSideView(TreeNode *root) {
		// 层序遍历，得到每一层的最后一个
		vector<int> res;
		if(root == nullptr) {
			return res;
		}
		queue<TreeNode *> que;
		que.push(root);
		while(!que.empty()) {
			res.push_back(que.back()->val);
			int size = que.size();
			for(int i = 0; i < size; i++) {
				TreeNode *top = que.front();
				que.pop();
				if(top->left)
					que.push(top->left);
				if(top->right)
					que.push(top->right);
			}
		}
		return res;
	}
};
// @lc code=end

