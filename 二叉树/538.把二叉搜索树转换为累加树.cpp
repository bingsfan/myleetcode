/*
 * @lc app=leetcode.cn id=538 lang=cpp
 *
 * [538] 把二叉搜索树转换为累加树
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
  void travel(TreeNode *node, int &sum)
  {
      if (node == nullptr)
      {
          return;
      }
      travel(node->right, sum);
      sum += node->val;
      node->val = sum;
      travel(node->left, sum);
  }
  TreeNode *convertBST(TreeNode *root)
  {
      int sum = 0;
      travel(root, sum);
      return root;
  }
};
// @lc code=end

