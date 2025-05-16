/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */

// @lc code=start
class Trie {
private:
	struct TrieNode {
		TrieNode *next[26];
		bool isEnd;
		TrieNode() {
			isEnd = false;
			memset(next, 0, sizeof(next));
		}
	};

public:
	TrieNode *root;
	Trie() {
		root = new TrieNode();
	}

	void insert(string word) {
		TrieNode *cur = root;
		for(auto &c : word) {
			int idx = c - 'a';
			if(cur->next[idx] == nullptr) {
				cur->next[idx] = new TrieNode;
			}
			cur = cur->next[idx];
		}
		cur->isEnd = true;
	}

	bool search(string word) {
		TrieNode *cur = root;
		for(auto &c : word) {
			int idx = c - 'a';
			if(cur->next[idx] == nullptr) {
				return false;
			}
			cur = cur->next[idx];
		}
		return cur->isEnd;
	}

	bool startsWith(string prefix) {
		TrieNode *cur = root;
		for(auto &c : prefix) {
			int idx = c - 'a';
			if(cur->next[idx] == nullptr) {
				return false;
			}
			cur = cur->next[idx];
		}
		return true;
	}
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

