# 这里写了目前做到的子数组/子串问题，可能不全

## 3. 无重复字符的最长子串

## 53. 最大子数组和

## 674. 最长连续递增序列

## 647. 回文子串

## 718. 最长重复子数组
滑动窗口解法
滑动窗口可以用于对齐两个数组的起始位置，然后逐字符比较公共部分。
核心思路：
固定 nums1，滑动 nums2：
将 nums1 的起始位置对齐 nums2 的某个位置，逐个比较元素。
固定 nums2，滑动 nums1：
类似地，将 nums2 的起始位置对齐 nums1 的某个位置。
记录最大匹配长度：在每次对齐时，统计连续相等的元素个数。

这个我没有实现。下面是deepseek实现的，感觉不如直接dp，这种两个数组比较的还是直接dp把。

``` cpp
#include <vector>
#include <algorithm>

using namespace std;

int findLength(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size(), n = nums2.size();
    int maxLen = 0;
    
    // nums1 固定，nums2 滑动
    for (int i = 0; i < m; i++) {
        int len = min(m - i, n);
        int currentLen = 0;
        for (int k = 0; k < len; k++) {
            if (nums1[i + k] == nums2[k]) {
                currentLen++;
                maxLen = max(maxLen, currentLen);
            } else {
                currentLen = 0;
            }
        }
    }
    
    // nums2 固定，nums1 滑动
    for (int j = 1; j < n; j++) {
        int len = min(m, n - j);
        int currentLen = 0;
        for (int k = 0; k < len; k++) {
            if (nums1[k] == nums2[j + k]) {
                currentLen++;
                maxLen = max(maxLen, currentLen);
            } else {
                currentLen = 0;
            }
        }
    }
    
    return maxLen;
}
```
## 5. 最长回文子串
可以用动态规划和滑动窗口解决