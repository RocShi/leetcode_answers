/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 *
 * https://leetcode.cn/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (59.00%)
 * Likes:    2751
 * Dislikes: 0
 * Total Accepted:    810.9K
 * Total Submissions: 1.4M
 * Testcase Example:  '"23"'
 *
 * 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按
 * 任意顺序 返回。
 *
 * 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
 *
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：digits = "23"
 * 输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]
 *
 *
 * 示例 2：
 *
 *
 * 输入：digits = ""
 * 输出：[]
 *
 *
 * 示例 3：
 *
 *
 * 输入：digits = "2"
 * 输出：["a","b","c"]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 0 <= digits.length <= 4
 * digits[i] 是范围 ['2', '9'] 的一个数字。
 *
 *
 */

// @lc code=start
class Solution {
public:
  vector<string> letterCombinations(string digits) {
    vector<string> result;

    if (!digits.empty()) {
      unordered_map<char, string> digits_letters_map = {
          {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
          {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
      string path;
      backtrack(digits, digits_letters_map, 0, result, path);
    }

    return result;
  }

  void backtrack(const string &digits,
                 const unordered_map<char, string> &digits_letters_map,
                 size_t start_idx, vector<string> &result, string &path) {
    if (path.size() == digits.size()) {
      result.emplace_back(path);
      return;
    }

    for (const char c : digits_letters_map.at(digits.at(start_idx))) {
      path.push_back(c);
      backtrack(digits, digits_letters_map, start_idx + 1, result, path);
      path.pop_back();
    }
  }
};
// @lc code=end
