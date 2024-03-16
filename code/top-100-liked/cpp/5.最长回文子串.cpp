/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 *
 * https://leetcode.cn/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (38.01%)
 * Likes:    7059
 * Dislikes: 0
 * Total Accepted:    1.6M
 * Total Submissions: 4.2M
 * Testcase Example:  '"babad"'
 *
 * 给你一个字符串 s，找到 s 中最长的回文子串。
 *
 * 如果字符串的反序与原始字符串相同，则该字符串称为回文字符串。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = "babad"
 * 输出："bab"
 * 解释："aba" 同样是符合题意的答案。
 *
 *
 * 示例 2：
 *
 *
 * 输入：s = "cbbd"
 * 输出："bb"
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length <= 1000
 * s 仅由数字和英文字母组成
 *
 *
 */

// @lc code=start
// 中心扩展实现
class Solution {
public:
  string longestPalindrome(string s) {
    string result, str1, str2;

    for (int i = 0; i < s.size(); ++i) {
      str1 = Palindrome(s, i, i);
      str2 = Palindrome(s, i, i + 1);
      result = str1.size() > result.size() ? str1 : result;
      result = str2.size() > result.size() ? str2 : result;
    }

    return result;
  }

  string Palindrome(string s, int left_idx, int right_idx) {
    while (left_idx >= 0 && right_idx < s.size() &&
           s.at(left_idx) == s.at(right_idx)) {
      --left_idx;
      ++right_idx;
    }
    return s.substr(left_idx + 1, right_idx - left_idx - 1);
  }
};
// @lc code=end
