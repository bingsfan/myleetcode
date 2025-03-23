/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] 删除二叉搜索树中的节点
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
    /*
    首先分析清楚删除节点的种类,这都是中止条件了才处理
    1.没有找到要删除的节点
    2.删的节点是叶子结点
    3.删的节点左空右不空
    4.删的节点左不空右空
    5.删的节点左右都不空
*/
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        // 终止条件
        if (root == nullptr)
        {
            return nullptr;
        }
        if (root->val == key)
        {
            if (!root->left && !root->right)
            {
                return nullptr;
            }
            else if (!root->left && root->right)
            {
                return root->right;
            }
            else if (root->left && !root->right)
            {
                return root->left;
            }
            else
            {
                // 这时候要找左子树的最大值
                TreeNode *cur = root->left;
                while (cur->right)
                {
                    cur = cur->right;
                }
                // 这时候cur就是左子树的最大值，把root的右子树加到cur的right上面
                cur->right = root->right;
                return root->left;
            }
        }
        if (root->val > key)
            root->left = deleteNode(root->left, key);
        if (root->val < key)
            root->right = deleteNode(root->right, key);
        return root;
    }
};
// @lc code=end
