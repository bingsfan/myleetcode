/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
 * nums1 中数字 x 的 下一个更大元素 是指 x 在 nums2 中对应位置 右侧 的 第一个 比 x 大的元素。
    给你两个 没有重复元素 的数组 nums1 和 nums2 ，下标从 0 开始计数，其中nums1 是 nums2 的子集。
    对于每个 0 <= i < nums1.length ，找出满足 nums1[i] == nums2[j] 的下标 j ，
    并且在 nums2 确定 nums2[j] 的 下一个更大元素 。如果不存在下一个更大元素，那么本次查询的答案是 -1 。
    返回一个长度为 nums1.length 的数组 ans 作为答案，满足 ans[i] 是如上所述的 下一个更大元素 。
 */

// @lc code=start
class Solution {
public:
/* 
    要从nums2中找比nums1[i]大的第一个元素的值，如果不存在那就是-1
    因此结果的数组肯定和nums1的长度一个，初始化都为-1
    能找到了再修改，找不到就不改
    要找大的元素，要一个从头到尾单调递增的栈

    遍历nums2数组，因为要从nums2中找
    如果nums[i]<=nums[st.top()]，那就直接入栈，因为单调递增栈
    否则
        这时候nums[i]>nums[st.top()]了
        要判断栈顶的元素是不是在nums1中出现过，如果出现过了，那么nums[i]就是我们得到的一个结果值
        这时候找到nums1中的索引，然后res[index]就是nums2[i]
            用一个map来存储<值，索引>，然后通过找nums[st.top()]得到index
        不管处不处理都要将栈顶的元素弹出，因为要保证栈的单调递增
*/
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1= nums1.size();
        int n2 = nums2.size();
        vector<int> res(n1,-1);
        stack<int> st;
        unordered_map<int,int> map;
        for(int i=0;i<n1;i++){
            map[nums1[i]]=i;
        }
        st.push(0);
        for(int i=1;i<n2;i++){
            if(nums2[i]<=nums2[st.top()]){
                st.push(i);
            }else{
                while(!st.empty()&&nums2[i]>nums2[st.top()]){
                    if(map.count(nums2[st.top()])>0){
                        int index = map[nums2[st.top()]];
                        res[index]=nums2[i];
                    }
                    st.pop();
                }
                st.push(i);
            }
        }
        return res;
    }
};
// @lc code=end

