/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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
string spath;
vector<string> res;
/*
	这种遍历整个树路径的一般都是中序遍历，然后要回溯
	弄两个全局变量先，一个string spath,一个vector<string> res
	先把头结点加进去，反正所有的输出都是有头结点的
	想想怎么处理到叶子节点的时候，其实就是把path里的数变成spath中的字符串结果就行了
	终止条件？root==nullptr return ;好像不要这个也行？试试先
	然后就是root为叶子结点的时候了
	妈的，这两个全局变量有问题，不能这样，全局变量直接污染了
	我他妈天才，path不能clear但是spath可以clear就ok了
*/
void addPath(TreeNode* root,vector<int> &path){
	// if(!root){
	// 	return;
	// }
	if(!root->left&&!root->right){
		for(int i=0;i<path.size()-1;i++){
			spath+=to_string(path[i]);
			spath+="->";
		}
		// 再把最后一个不要箭头的加进去
		spath+=to_string(path[path.size()-1]);
		res.push_back(spath);
        spath.clear();
		return;
		// 感觉这里可以不return？在下面为空的时候也会return，测试了没问题，
		// 两个return有一个就行了，这个包含了为空的情况，因为根本不会执行过去
	}
	// 下面就递归处理左右子树就行了
	// 这里必须要用if判断，不然要加进去的path没有值捏
	if(root->left){
		path.push_back(root->left->val);
		addPath(root->left,path);
		path.pop_back();
	}
	if(root->right){
		path.push_back(root->right->val);
		addPath(root->right,path);
		path.pop_back();
	}
}
vector<string> binaryTreePaths(TreeNode* root) {
    vector<int> path;
    path.push_back(root->val);
    addPath(root,path);
    return res;
}
};
// @lc code=end

