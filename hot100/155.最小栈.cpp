/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

// @lc code=start
class MinStack {
public:
	stack<int> st;
	stack<int> min_st;
	MinStack() {}

	void push(int val) {
		st.push(val);
		if(min_st.empty()) {
			min_st.push(val);
		} else {
			if(min_st.top() >= val) {
				min_st.push(val);
			}
		}
	}

	void pop() {
		int top = st.top();
		st.pop();
		if(top == min_st.top()) {
			min_st.pop();
		}
	}

	int top() {
		return st.top();
	}

	int getMin() {
		return min_st.top();
	}
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

