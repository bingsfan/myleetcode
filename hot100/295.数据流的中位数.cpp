/*
 * @lc app=leetcode.cn id=295 lang=cpp
 *
 * [295] 数据流的中位数
 */

// @lc code=start
class MedianFinder {
private:
	priority_queue<int, vector<int>, less<int>> big;
	priority_queue<int, vector<int>, greater<int>> small;

public:
	MedianFinder() {}

	void addNum(int num) {
		big.push(num);
		small.push(big.top());
		big.pop();
		if(small.size() > big.size()) {
			big.push(small.top());
			small.pop();
		}
	}
	double findMedian() {
		if(big.size() != small.size()) {
			return big.top();
		} else {
			return (big.top() + small.top()) / 2.0;
		}
	}
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end

