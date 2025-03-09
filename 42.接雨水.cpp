/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution {
public:
/* 
    和前几个的思路很像，只是多了对于面积的处理，也是要找左边和右边第一个比现在这个元素大的
    总结一下就是在遇到无法保持栈的单调的时候就要进行处理，这几道题都是无法保证递增了处理
    基本都是套用模板，不过这个是用到了三个数据进行计算， 之前是两个
*/

    int trap(vector<int>& height) {
        int n = height.size();
        if(n<=2) return 0;
        stack<int> st;
        int res=0;
        st.push(0);
        for(int i=1;i<n;i++){
            if(height[i]<=height[st.top()]){
                st.push(i);
            }else{
                while(!st.empty()&&height[i]>height[st.top()]){
                    int mid = st.top();
                    st.pop();
                    if(!st.empty()){
                        int h = min(height[i],height[st.top()])-height[mid];
                        int w = i-st.top()-1;
                        res+=w*h;
                    }
                }
                st.push(i);
            }
        }
        return res;
    }
};
// @lc code=end

