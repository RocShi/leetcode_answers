/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 *
 * https://leetcode.cn/problems/minimum-window-substring/description/
 *
 * algorithms
 * Hard (45.52%)
 * Likes:    2820
 * Dislikes: 0
 * Total Accepted:    513.5K
 * Total Submissions: 1.1M
 * Testcase Example:  '"ADOBECODEBANC"\n"ABC"'
 *
 * 给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s
 * 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。
 *
 *
 *
 * 注意：
 *
 *
 * 对于 t 中重复字符，我们寻找的子字符串中该字符数量必须不少于 t 中该字符数量。
 * 如果 s 中存在这样的子串，我们保证它是唯一的答案。
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = "ADOBECODEBANC", t = "ABC"
 * 输出："BANC"
 * 解释：最小覆盖子串 "BANC" 包含来自字符串 t 的 'A'、'B' 和 'C'。
 *
 *
 * 示例 2：
 *
 *
 * 输入：s = "a", t = "a"
 * 输出："a"
 * 解释：整个字符串 s 是最小覆盖子串。
 *
 *
 * 示例 3:
 *
 *
 * 输入: s = "a", t = "aa"
 * 输出: ""
 * 解释: t 中两个字符 'a' 均应包含在 s 的子串中，
 * 因此没有符合条件的子字符串，返回空字符串。
 *
 *
 *
 * 提示：
 *
 *
 * ^m == s.length
 * ^n == t.length
 * 1 <= m, n <= 10^5
 * s 和 t 由英文字母组成
 *
 *
 *
 * 进阶：你能设计一个在 o(m+n) 时间内解决此问题的算法吗？
 */

// @lc code=start
// 滑动窗口实现，与“3.无重复字符的最长子串”和“438.找到字符串中所有字母异位词”都有相似
// 之处
class Solution {
public:
  string minWindow(string s, string t) {
    int left_idx = 0, right_idx = 0, matched_letters_num = 0;
    int result_start_idx = -1, result_len = numeric_limits<int>::max();
    unordered_map<char, int> feature, window;

    for (const char c : t) {
      ++feature[c];
    }

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

      while (matched_letters_num == feature.size()) {
        if (right_idx - left_idx < result_len) {
          result_start_idx = left_idx;
          result_len = right_idx - left_idx;
        }

        char left_char = s.at(left_idx);
        ++left_idx;

        iter = feature.find(left_char);
        if (iter != feature.end()) {
          --window[left_char];
          if (window[left_char] < iter->second) {
            --matched_letters_num;
          }
        }
      }
    }

    return result_start_idx == -1 ? "" : s.substr(result_start_idx, result_len);
  }
};
// @lc code=end
