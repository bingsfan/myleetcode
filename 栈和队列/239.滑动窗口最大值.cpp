/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
class Solution
{
  public:
/* 
    这个题做的有点不熟练
    在设计单调队列的时候：push操作如果队列非空且要加入的值比队尾元素大，那队尾元素滚出去，因为要维持递减的特性
    pop操作的时候，如果pop的元素和队头元素相等就pop出去，不相等就不用管
*/
    struct myqueue
    {
        deque<int> q;
        void push(int k)
        {
            while (!q.empty() && k > q.back())
            {
                q.pop_back();
            }
            q.push_back(k);
        }
        void pop(int k)
        {
            if (!q.empty() && k == q.front())
            {
                q.pop_front();
            }
        }
        int front()
        {
            return q.front();
        }
    };

    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        myqueue que;
        vector<int> res;
        for (int i = 0; i < k; i++)
        {
            que.push(nums[i]);
        }
        res.push_back(que.front());
        for (int i = k; i < nums.size(); i++)
        {
            que.pop(nums[i - k]);
            que.push(nums[i]);
            res.push_back(que.front());
        }
        return res;
    }
};
// @lc code=end
