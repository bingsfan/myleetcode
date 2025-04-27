/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
class Solution {
public:
	string minWindow(string s, string t) {
		unordered_map<char, int> need, window;
		for(char c : t) {
			need[c]++;
		}
		int left = 0, right = 0;
		int valid = 0;
		int len	  = INT_MAX;
		int start = 0;
		for(; right < s.size(); right++) {
			char c = s[right];
			// 更新两个map
			if(need.count(c)) {
				window[c]++;
				if(window[c] == need[c]) {
					valid++;
				}
			} else {
				window[c]++;
			}
			// 判断是否需要移动left
			while(valid == need.size()) {
				if(right - left + 1 < len) {
					len	  = right - left + 1;
					start = left;
				}
				char d = s[left];
				left++;
				if(need.count(d)) {
					if(window[d] == need[d]) {
						valid--;
					}
					window[d]--;
				} else {
					window[d]--;
				}
			}
		}
		return len == INT_MAX ? "" : s.substr(start, len);
	}
};
// @lc code=end

