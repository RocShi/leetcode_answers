/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 *
 * https://leetcode.cn/problems/find-all-anagrams-in-a-string/description/
 *
 * algorithms
 * Medium (53.96%)
 * Likes:    1373
 * Dislikes: 0
 * Total Accepted:    369.4K
 * Total Submissions: 684.5K
 * Testcase Example:  '"cbaebabacd"\n"abc"'
 *
 * 给定两个字符串 s 和
 * p，找到 s 中所有 p 的 异位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。
 *
 * 异位词 指由相同字母重排列形成的字符串（包括相同的字符串）。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: s = "cbaebabacd", p = "abc"
 * 输出: [0,6]
 * 解释:
 * 起始索引等于 0 的子串是 "cba", 它是 "abc" 的异位词。
 * 起始索引等于 6 的子串是 "bac", 它是 "abc" 的异位词。
 *
 *
 * 示例 2:
 *
 *
 * 输入: s = "abab", p = "ab"
 * 输出: [0,1,2]
 * 解释:
 * 起始索引等于 0 的子串是 "ab", 它是 "ab" 的异位词。
 * 起始索引等于 1 的子串是 "ba", 它是 "ab" 的异位词。
 * 起始索引等于 2 的子串是 "ab", 它是 "ab" 的异位词。
 *
 *
 *
 *
 * 提示:
 *
 *
 * 1 <= s.length, p.length <= 3 * 10^4
 * s 和 p 仅包含小写字母
 *
 *
 */

// @lc code=start
// 使用滑动窗口统计字母数量
class Solution {
public:
  vector<int> findAnagrams(string s, string p) {
    vector<int> result;
    unordered_map<char, int> feature, window;
    for (const char c : p) {
      ++feature[c];
    }

    int left_idx = 0, right_idx = 0, matched_letters_num = 0;
    while (right_idx < s.size()) {
      char right_char = s.at(right_idx);
      ++right_idx;

      auto iter = feature.find(right_char);
      if (iter != feature.end()) {
        ++window[right_char];
        if (window[right_char] == iter->second) {
          ++matched_letters_num;
        }
      }

      if (matched_letters_num == feature.size()) {
        result.emplace_back(left_idx);
      }

      if (right_idx - left_idx == p.size()) {
        char left_char = s.at(left_idx);
        ++left_idx;

        iter = feature.find(left_char);
        if (iter != feature.end()) {
          if (window[left_char] == iter->second) {
            --matched_letters_num;
          }
          --window[left_char];
        }
      }
    }

    return result;
  }
};
// @lc code=end
