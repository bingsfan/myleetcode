/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 * 给定一个整数数组 temperatures ，表示每天的温度，返回一个数组 answer ，
 * 其中 answer[i] 是指对于第 i 天，下一个更高温度出现在几天后。
 * 如果气温在这之后都不会升高，请在该位置用 0 来代替。
 */

// @lc code=start
class Solution {
public:
/* 
    这个题需要自己构建一个单调栈，栈里面存储的是数组的下标
    解决的是找右边第一个比本元素更大的下标
    要使用递增次序，即栈头到栈尾是递增的
    使用单调栈主要有三个判断条件：
        当前遍历的元素T[i]小于栈顶元素T[st.top()]的情况，直接入栈
        当前遍历的元素T[i]等于栈顶元素T[st.top()]的情况，也直接入栈
        当前遍历的元素T[i]大于栈顶元素T[st.top()]的情况，一直弹出栈顶元素，直到栈为空或者T[i]不再大于栈顶元素为止
*/
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        int n = temperatures.size();
        vector<int> res(n,0);
        st.push(0);
        for(int i=1;i<n;i++){
            if(temperatures[i]<=temperatures[st.top()]){
                st.push(i);
            }else{
                while(!st.empty()&&temperatures[i]>temperatures[st.top()]){
                    res[st.top()]=i-st.top();
                    st.pop();
                }
                st.push(i);
            }
        }
        return res;
    }
};
// @lc code=end

