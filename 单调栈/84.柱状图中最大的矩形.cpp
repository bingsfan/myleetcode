/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

// @lc code=start
class Solution {
public:
	/*
		这个题不一样的点在于要找左右两侧比当前元素小的第一个位置
		因此当当前元素比栈顶小，才开始处理，并且有两种极端情况，一直递增或者递减，这时候没法处理
		因此头尾都要添加一个0
	*/
	int largestRectangleArea(vector< int > &heights) {
		stack< pair< int, int > > st;
		int res = 0;
		heights.insert(heights.begin(), 0);
		heights.push_back(0);
		for(int i = 0; i < heights.size(); i++) {
			while(!st.empty() && heights[i] < st.top().first) {
				int rightHeight	 = heights[i];
				int right		 = i;
				int bottomHeight = st.top().first;
				int bottom		 = st.top().second;
				st.pop();
				if(st.empty()) {
					res = max(res, bottomHeight);
					break;
				}
				int leftHeight = st.top().first;
				int left	   = st.top().second;
				int w		   = right - left - 1;
				int h		   = bottomHeight;
				res			   = max(res, w * h);
			}
			st.push(pair< int, int >(heights[i], i));
		}
		return res;
	}
};
// @lc code=end
