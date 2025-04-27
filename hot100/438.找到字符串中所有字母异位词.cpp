/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
class Solution {
public:
	vector<int> findAnagrams(string s, string p) {
		vector<int> res;
		if(s.size()<p.size()){
			return res;
		}
		vector<int> s_count(26, 0), p_count(26, 0);
		int size = p.size();
		for(int i = 0; i < size; i++) {
			s_count[s[i] - 'a']++;
			p_count[p[i] - 'a']++;
		}
		if(s_count == p_count) {
			res.push_back(0);
		}
		for(int i = size; i < s.size(); i++) {
			s_count[s[i] - 'a']++;
			s_count[s[i - size] - 'a']--;
			if(s_count == p_count) {
				res.push_back(i - size + 1);
			}
		}
		return res;
	}
};
// @lc code=end

