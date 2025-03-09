/*
 * @lc app=leetcode.cn id=503 lang=cpp
 *
 * [503] 下一个更大元素 II
 * 给定一个循环数组 nums ，返回 nums 中每个元素的 下一个更大元素 。
    数字 x 的 下一个更大的元素 是按数组遍历顺序，这个数字之后的第一个比它更大的数
    这意味着你应该循环地搜索它的下一个更大的数。如果不存在，则输出 -1 。
 */

// @lc code=start
class Solution {
public:
/* 
    直接将数组扩容两倍好理解一点，然后核心代码和上一道题基本一样
    不过不用映射过来了
*/
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> nums1(n*2);
        for(int i=0;i<n*2;i++){
            nums1[i]=nums[i%n];
        }
        stack<int> st;
        vector<int> res(n*2,-1);
        st.push(0);
        for(int i=1;i<n*2;i++){
            if(nums1[i]<=nums1[st.top()])
                st.push(i);
            else{
                while(!st.empty()&&nums1[i]>nums1[st.top()]){
                    res[st.top()]=nums1[i];
                    st.pop();
                }
                st.push(i);
            }
        }
        res.resize(n);
        return res;
    }
};
// @lc code=end

