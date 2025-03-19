/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */

// @lc code=start
class MyQueue
{
    /*
        重点是push的时候直接push到st1，输入栈就好
        pop 的时候如果st2输出栈不为空，直接输出，如果为空则需要把st1中的数据全加载到st2再输出
    */
  public:
    stack<int> st1;
    stack<int> st2;
    MyQueue()
    {
    }

    void push(int x)
    {
        st1.push(x);
    }

    int pop()
    {
        int res;
        if (!st2.empty())
        {
            res = st2.top();
            st2.pop();
        }
        else
        {
            while (!st1.empty())
            {
                int top = st1.top();
                st1.pop();
                st2.push(top);
            }
            res = st2.top();
            st2.pop();
        }
        return res;
    }

    int peek()
    {
        int res;
        if (!st2.empty())
        {
            res = st2.top();
        }
        else
        {
            while (!st1.empty())
            {
                int top = st1.top();
                st1.pop();
                st2.push(top);
            }
            res = st2.top();
        }
        return res;
    }

    bool empty()
    {
        return st1.empty() && st2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end
