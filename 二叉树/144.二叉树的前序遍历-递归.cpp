/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
  vector<int> res;
  void preTravel(TreeNode *cur)
  {
      if (cur == nullptr)
      {
          return;
      }
      res.push_back(cur->val);
      preTravel(cur->left);
      preTravel(cur->right);
      return;
  }
  vector<int> preorderTraversal(TreeNode *root)
  {
      preTravel(root);
      return res;
  }
};
// @lc code=end

