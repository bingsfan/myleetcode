/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

// @lc code=start
class Solution {
public:

/* 
    宽度都是1，这时候要找的是左边和右边第一个比当前元素小的
    不过这个在处理数组的时候需要前后都补一个0
*/
    int largestRectangleArea(vector<int>& heights) {
        heights.insert(heights.begin(),0);
        heights.push_back(0);
        int n  =  heights.size();
        stack<int> st;
        st.push(0);
        int res=0;

        for(int i=1;i<n;i++){
            if(heights[i]>=heights[st.top()]){
                st.push(i);
            }else{
                while(st.size()>1&&heights[i]<heights[st.top()]){
                    int mid  = st.top();
                    st.pop();
                    int left = st.top();
                    int right = i;
                    int w = right-left-1;
                    int h = heights[mid];
                    res = max(res,w*h);
                }
                st.push(i);
            }
        }
        return res;
    }
};
// @lc code=end

