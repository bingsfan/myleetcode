/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
class Solution {
public:
	int jump(vector<int> &nums) {
		int n		   = nums.size();
		int res		   = 1;
        if(n==1){
            return 0;
        }
		int curborder  = nums[0];
		int nextborder = curborder;
		if(nextborder >= n - 1) {
			return res;
		}
		for(int i = 0; i < n; i++) {
			nextborder = max(nextborder, i + nums[i]);
			if(i == curborder) {
				res++;
				curborder = nextborder;
				if(nextborder >= n - 1) {
					break;
				}
			}
		}
		return res;
	}
};
// @lc code=end

