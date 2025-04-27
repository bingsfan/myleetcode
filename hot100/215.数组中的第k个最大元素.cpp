/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
class Solution {
public:
	/* int findKthLargest(vector<int> &nums, int k) {
		priority_queue<int, vector<int>, less<int>> pq;
		for(auto &num : nums) {
			pq.push(num);
		}
		int res = 0;
		while(k--) {
			res = pq.top();
			pq.pop();
		}
		return res;
	} */
	struct MyMaxHeap {
	private:
		vector<int> heap;
		void up(int i) {
			int parent = (i - 1) / 2;
			if(heap[i] > heap[parent]) {
				swap(heap[i], heap[parent]);
				up(parent);
			}
		}
		void down(int i) {
			int l = 2 * i + 1, r = 2 * i + 2;
			int largest = i;
			// 找出三个元素中最大的
			if(l < heap.size() && heap[l] > heap[largest]) {
				largest = l;
			}
			if(r < heap.size() && heap[r] > heap[largest]) {
				largest = r;
			}
			if(largest != i) {
				swap(heap[i], heap[largest]);
				down(largest);
			}
		}

	public:
		int size() {
			return heap.size();
		}
		void push(int val) {
			heap.push_back(val);
			up(heap.size() - 1);
		}
		void pop() {
			swap(heap[0], heap.back());
			heap.pop_back();
			down(0);
		}
		int top() {
			return heap[0];
		}
	};

	int findKthLargest(vector<int> &nums, int k) {
		MyMaxHeap myheap;
		for(auto &num : nums) {
			myheap.push(num);
		}
		int res;
		while(k--) {
			res = myheap.top();
			myheap.pop();
		}
		return res;
	}    
   
//    上面的是自己实现的类
};
// @lc code=end

