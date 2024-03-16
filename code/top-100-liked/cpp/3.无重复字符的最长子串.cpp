/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 *
 * https://leetcode.cn/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (39.47%)
 * Likes:    9962
 * Dislikes: 0
 * Total Accepted:    2.7M
 * Total Submissions: 6.8M
 * Testcase Example:  '"abcabcbb"'
 *
 * 给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: s = "abcabcbb"
 * 输出: 3
 * 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
 *
 *
 * 示例 2:
 *
 *
 * 输入: s = "bbbbb"
 * 输出: 1
 * 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
 *
 *
 * 示例 3:
 *
 *
 * 输入: s = "pwwkew"
 * 输出: 3
 * 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
 * 请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 0 <= s.length <= 5 * 10^4
 * s 由英文字母、数字、符号和空格组成
 *
 *
 */

// @lc code=start
// 滑动窗口实现
class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int result = 0;
    unordered_map<char, int> window;
    int left_idx = 0, right_idx = 0;

    while (right_idx < s.size()) {
      char right_char = s.at(right_idx);
      ++right_idx;
      ++window[right_char];

      while (window[right_char] > 1) {
        char left_char = s.at(left_idx);
        ++left_idx;
        --window[left_char];
      }

      result = max(result, right_idx - left_idx);
    }

    return result;
  }
};
// @lc code=end
