/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */

// @lc code=start
class MyStack
{
    /*
        push的时候直接加入q1后面，
        pop的时候q1一直出队，加入到q2，直到q1中只有一个元素，再出队就行了
        pop结束再将q2里面的所有值加入q1
    */
  public:
    queue<int> q1;
    queue<int> q2;

    MyStack()
    {
    }

    void push(int x)
    {
        q1.push(x);
    }

    int pop()
    {
        while (q1.size() != 1)
        {
            int top = q1.front();
            q1.pop();
            q2.push(top);
        }
        int res = q1.front();
        q1.pop();
        while (!q2.empty())
        {
            int top = q2.front();
            q2.pop();
            q1.push(top);
        }
        return res;
    }

    int top()
    {
        while (q1.size() != 1)
        {
            int top = q1.front();
            q1.pop();
            q2.push(top);
        }
        int res = q1.front();
        q1.pop();
        q2.push(res);
        while (!q2.empty())
        {
            int top = q2.front();
            q2.pop();
            q1.push(top);
        }
        return res;
    }

    bool empty()
    {
        return q1.empty() && q2.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

