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
    /*
        两个数组的长度都至少为1，但是还是得判断之后的数组是不是为空
        构造一般都是前序遍历
        还得新写一个函数，带返回值的，因为要用，未必？
    */
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        // 有的子树是空的，这就得处理一下，不能说原先的不是空就不处理了
        if (postorder.size() == 0)
        {
            return nullptr;
        }
        // 这是中节点的处理逻辑，因为要找中节点在哪
        int rootVal = postorder.back();
        int index;
        for (int i = 0; i < inorder.size(); i++)
        {
            if (inorder[i] == rootVal)
            {
                index = i;
            }
        }
        // 找到两个数组的root值和索引了，现在要分割两个数组，拿inorder来处理，因为post可以复用这个长度
        // 这里vector的构造体都是左闭右开区间的
        vector<int> leftin(inorder.begin(), inorder.begin() + index);
        vector<int> rightin(inorder.begin() + index + 1, inorder.end());
        // 让post数组最后一个直接滚蛋，因为它是确定不要的,但是让他滚蛋后我得先把根节点拿下
        postorder.pop_back();
        vector<int> leftpost(postorder.begin(), postorder.begin() + leftin.size());
        vector<int> rightpost(postorder.begin() + leftpost.size(), postorder.end());
        TreeNode *root = new TreeNode(rootVal);
        // 要用变量接接返回值啊，我草你妈的
        root->left = buildTree(leftin, leftpost);
        root->right = buildTree(rightin, rightpost);
        return root;
    }
};
// @lc code=end
