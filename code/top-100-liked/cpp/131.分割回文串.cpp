/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 *
 * https://leetcode.cn/problems/palindrome-partitioning/description/
 *
 * algorithms
 * Medium (73.46%)
 * Likes:    1731
 * Dislikes: 0
 * Total Accepted:    360.2K
 * Total Submissions: 490.2K
 * Testcase Example:  '"aab"'
 *
 * 给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是 回文串 。返回 s
 * 所有可能的分割方案。
 *
 * 回文串 是正着读和反着读都一样的字符串。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = "aab"
 * 输出：[["a","a","b"],["aa","b"]]
 *
 *
 * 示例 2：
 *
 *
 * 输入：s = "a"
 * 输出：[["a"]]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * s 仅由小写英文字母组成
 *
 *
 */

// @lc code=start
// 回溯方法解决
class Solution {
public:
  vector<vector<string>> partition(string s) {
    vector<vector<string>> result;
    vector<string> path;
    backtrack(s, result, path, 0);
    return result;
  }

  void backtrack(const string &s, vector<vector<string>> &result,
                 vector<string> &path, int left_idx) {
    if (left_idx >= s.size()) {
      result.emplace_back(path);
      return;
    }

    for (int right_idx = left_idx; right_idx < s.size(); ++right_idx) {
      if (isPalindrome(s, left_idx, right_idx)) {
        path.emplace_back(s.substr(left_idx, right_idx - left_idx + 1));
        backtrack(s, result, path, right_idx + 1);
        path.pop_back();
      }
    }
  }

  bool isPalindrome(const string &s, int left_idx, int right_idx) {
    while (left_idx <= right_idx) {
      if (s.at(left_idx) != s.at(right_idx)) {
        return false;
      }
      ++left_idx;
      --right_idx;
    }
    return true;
  }
};
// @lc code=end
