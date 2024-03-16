/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 *
 * https://leetcode.cn/problems/longest-valid-parentheses/description/
 *
 * algorithms
 * Hard (37.63%)
 * Likes:    2447
 * Dislikes: 0
 * Total Accepted:    422.5K
 * Total Submissions: 1.1M
 * Testcase Example:  '"(()"'
 *
 * 给你一个只包含 '(' 和
 * ')' 的字符串，找出最长有效（格式正确且连续）括号子串的长度。
 *
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = "(()"
 * 输出：2
 * 解释：最长有效括号子串是 "()"
 *
 *
 * 示例 2：
 *
 *
 * 输入：s = ")()())"
 * 输出：4
 * 解释：最长有效括号子串是 "()()"
 *
 *
 * 示例 3：
 *
 *
 * 输入：s = ""
 * 输出：0
 *
 *
 *
 *
 * 提示：
 *
 *
 * 0
 * s[i] 为 '(' 或 ')'
 *
 *
 *
 *
 */

// @lc code=start
// 栈 + 哨兵节点实现
class Solution {
public:
  int longestValidParentheses(string s) {
    int result = 0;
    stack<int> indices_stack;
    indices_stack.push(-1);

    for (int i = 0; i < s.size(); ++i) {
      if (s.at(i) == '(') {
        indices_stack.push(i);
      } else {
        indices_stack.pop();

        if (indices_stack.empty()) {
          indices_stack.push(i);
        } else {
          result = max(result, i - indices_stack.top());
        }
      }
    }

    return result;
  }
};
// @lc code=end
