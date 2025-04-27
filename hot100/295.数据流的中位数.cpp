/*
 * @lc app=leetcode.cn id=295 lang=cpp
 *
 * [295] 数据流的中位数
 */

// @lc code=start
class MedianFinder {
	// 先用排序数组实现，再用两个堆实现
public:
	priority_queue<int, vector<int>, greater<int>> minHeap;
	priority_queue<int, vector<int>, less<int>> maxHeap;

	MedianFinder() {}

	void addNum(int num) {
		// 大堆要存较小的数，先存完在调整
		maxHeap.push(num);
		minHeap.push(maxHeap.top());
		maxHeap.pop();
		if(minHeap.size() > maxHeap.size()) {
			maxHeap.push(minHeap.top());
			minHeap.pop();
		}
	}

	double findMedian() {
		if(maxHeap.size() != minHeap.size()) {
			return maxHeap.top();
		} else {
			return (maxHeap.top() + minHeap.top()) / 2.0;
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

