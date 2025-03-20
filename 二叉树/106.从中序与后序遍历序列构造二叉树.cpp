/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
class Solution
{
  public:
    TreeNode *travel(vector<int> &inorder, vector<int> &postorder)
    {
        if (postorder.size() == 0)
        {
            return nullptr;
        }
        int rootVal = postorder.back();
        TreeNode *root = new TreeNode(rootVal);
        int index = 0;
        for (; index < inorder.size(); index++)
        {
            if (inorder[index] == rootVal)
            {
                break;
            }
        }
        // 切割中序数组
        vector<int> leftIn(inorder.begin(), inorder.begin() + index);
        vector<int> rightIn(inorder.begin() + index + 1, inorder.end());
        // 切割后序数组
        vector<int> leftPost(postorder.begin(), postorder.begin() + leftIn.size());
        postorder.pop_back();
        vector<int> rightPost(postorder.begin() + leftIn.size(), postorder.end());
        // 递归左右子树
        root->left = travel(leftIn, leftPost);
        root->right = travel(rightIn, rightPost);
        return root;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        return travel(inorder, postorder);
    }
};
// @lc code=end
