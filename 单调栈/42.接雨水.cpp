/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution {
public:
	/*
	依然是用一个pair的单调递减栈，当遇到比栈顶元素大的时候开始计算面积
	注意if(st.empty())
			break;
	如果弹出之后栈已经空了，就不可能累计雨水，而且后面还要继续取栈顶的元素，肯定需要判断
	*/
	int trap(vector< int > &height) {
		stack< pair< int, int > > st;
		int res = 0;
		for(int i = 0; i < height.size(); i++) {
			while(!st.empty() && height[i] > st.top().first) {
				int rightHeight	 = height[i];
				int right		 = i;
				int bottomHeight = st.top().first;
				int bottom		 = st.top().second;
				st.pop();
				if(st.empty()) {
					break;
				}
				int leftHeight = st.top().first;
				;
				int left = st.top().second;
				int w	 = right - left - 1;
				int h	 = min(rightHeight, leftHeight) - bottomHeight;
				res += w * h;
			}
			st.push(pair< int, int >(height[i], i));
		}
		return res;
	}
};
// @lc code=end
