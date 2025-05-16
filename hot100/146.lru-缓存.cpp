/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
 */

// @lc code=start
// !自己实现的
struct dNode {
	int key, value;
	dNode *next;
	dNode *prev;
	dNode(int k, int v) : key(k), value(v), next(nullptr), prev(nullptr) {}
};
class LRUCache {
private:
	dNode *dhead;
	dNode *dtail;
	int capacity;
	unordered_map<int, dNode *> umap;
	// 删除双向链表的一个节点
	void remove(dNode *node) {
		node->prev->next = node->next;
		node->next->prev = node->prev;
	}
	void insertFront(dNode *node) {
		node->next		 = dhead->next;
		node->prev		 = dhead;
		dhead->next		 = node;
		node->next->prev = node;
	}

public:
	LRUCache(int capacity) {
		dhead		   = new dNode(0, 0);
		dtail		   = new dNode(0, 0);
		dhead->next	   = dtail;
		dtail->prev	   = dhead;
		this->capacity = capacity;
	}

	int get(int key) {
		if(!umap.count(key)) {
			return -1;
		}
		auto it	  = umap[key];
		int value = it->value;
		remove(it);
		dNode *node = new dNode(key, value);
		insertFront(node);
		umap[key] = dhead->next;
		return value;
	}

	void put(int key, int value) {
		if(umap.count(key)) {
			auto it = umap[key];
			remove(it);
			umap.erase(key);
		}
		dNode *node = new dNode(key, value);
		insertFront(node);
		umap[key] = dhead->next;
		if(umap.size() > capacity) {
			auto last  = dtail->prev;
			int delKey = last->key;
			remove(last);
			umap.erase(delKey);
		}
	}
};
// !使用list的迭代器实现的
/* class LRUCache {
public:
	typedef pair<int, int> pli;
	int capacity;
	list<pli> cache;
	unordered_map<int, list<pair<int, int>>::iterator> map;
	LRUCache(int capacity) {
		this->capacity = capacity;
	}

	int get(int key) {
		if(!map.count(key)) {
			return -1;
		}
		// 把找到的这个节点放在链表头，因为刚查了，使用了
		auto it	  = map[key];
		int value = it->second;
		cache.erase(it);
		cache.push_front({ key, value });
		map[key] = cache.begin();
		return value;
	}

	void put(int key, int value) {
		// 如果key已经在map中存在就先在map和list中都删除掉，之后再在链表的头结点插入
		if(map.count(key)) {
			cache.erase(map[key]);
			map.erase(key);
		}
		// 插到链表头
		cache.push_front({ key, value });
		map[key] = cache.begin();
		// 如果链表的长度超过capacity，在链表中pop，map中删除
		if(cache.size() > capacity) {
			auto last = cache.back();
			cache.pop_back();
			map.erase(last.first);
		}
	}
} ;*/
/* class LRUCache {
private:
	unordered_map<int, list<pair<int, int>>::iterator> umap;
	int capacity;
	list<pair<int, int>> list;

public:
	LRUCache(int capacity) {
		this->capacity = capacity;
	}
	int get(int key) {
		if(!umap.count(key)) {
			return -1;
		}
		auto it = umap[key];
		int val = it->second;
		list.erase(it);
		list.push_front({ key, val });
		umap[key] = list.begin();
		return val;
	}
	void put(int key, int value) {
		// 如果umap中没有，直接添加进去，如果有的话要删了然后添加
		if(!umap.count(key)) {
			list.push_front({ key, value });
		} else {
			auto it = umap[key];
			umap.erase(key);
			int val = it->second;
			list.erase(it);
			list.push_front({ key, value });
		}
		umap[key] = list.begin();
		if(list.size() > capacity) {
			umap.erase(list.back().first);
			list.pop_back();
		}
	}
}; */
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

