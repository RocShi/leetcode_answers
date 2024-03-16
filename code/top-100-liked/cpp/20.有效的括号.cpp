/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 *
 * https://leetcode.cn/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (43.89%)
 * Likes:    4339
 * Dislikes: 0
 * Total Accepted:    1.7M
 * Total Submissions: 3.9M
 * Testcase Example:  '"()"'
 *
 * 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
 *
 * 有效字符串需满足：
 *
 *
 * 左括号必须用相同类型的右括号闭合。
 * 左括号必须以正确的顺序闭合。
 * 每个右括号都有一个对应的相同类型的左括号。
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = "()"
 * 输出：true
 *
 *
 * 示例 2：
 *
 *
 * 输入：s = "()[]{}"
 * 输出：true
 *
 *
 * 示例 3：
 *
 *
 * 输入：s = "(]"
 * 输出：false
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length <= 10^4
 * s 仅由括号 '()[]{}' 组成
 *
 *
 */

// @lc code=start
// 栈实现
class Solution {
public:
  bool isValid(string s) {
    if (s.size() % 2 == 1) {
      return false;
    }

    unordered_map<char, char> symbols_map = {
        {')', '('}, {'}', '{'}, {']', '['}};
    stack<char> left_symbols_stack;

    for (const char c : s) {
      if (c == '(' || c == '{' || c == '[') {
        left_symbols_stack.push(c);
      } else {
        if (!left_symbols_stack.empty()) {
          if (symbols_map.at(c) == left_symbols_stack.top()) {
            left_symbols_stack.pop();
          } else {
            return false;
          }
        } else {
          return false;
        }
      }
    }

    return left_symbols_stack.empty();
  }
};
// @lc code=end
