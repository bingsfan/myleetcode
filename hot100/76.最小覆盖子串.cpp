/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
class Solution {
public:
string minWindow(string s, string t) {
	unordered_map<char, int> s_hash, t_hash;
	int n = s.size(), m = t.size();
	for(auto &c : t) {
		t_hash[c]++;
	}
	int left = 0, right = 0;
	int valid = 0;
	int len	  = INT_MAX;
	int start = 0;
	for(; right < n; right++) {
		char c = s[right];
		s_hash[c]++;
		if(t_hash.count(c) && s_hash[c] == t_hash[c]) {
			valid++;
		}
		while(valid == t_hash.size()) {
			if(right - left + 1 < len) {
				len	  = right - left + 1;
				start = left;
			}
			char d = s[left];
			left++;
			if(t_hash.count(d) && s_hash[d] == t_hash[d]) {
				valid--;
			}
			s_hash[d]--;
			if(s_hash[d] == 0) {
				s_hash.erase(d);
			}
		}
	}
	return len == INT_MAX ? "" : s.substr(start, len);
}
};
// @lc code=end

