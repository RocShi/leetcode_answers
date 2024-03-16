/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] 字符串解码
 *
 * https://leetcode.cn/problems/decode-string/description/
 *
 * algorithms
 * Medium (57.21%)
 * Likes:    1680
 * Dislikes: 0
 * Total Accepted:    287.1K
 * Total Submissions: 501.6K
 * Testcase Example:  '"3[a]2[bc]"'
 *
 * 给定一个经过编码的字符串，返回它解码后的字符串。
 *
 * 编码规则为: k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复 k
 * 次。注意 k 保证为正整数。
 *
 * 你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。
 *
 * 此外，你可以认为原始数据不包含数字，所有的数字只表示重复的次数 k
 * ，例如不会出现像 3a 或 2[4] 的输入。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = "3[a]2[bc]"
 * 输出："aaabcbc"
 *
 *
 * 示例 2：
 *
 *
 * 输入：s = "3[a2[c]]"
 * 输出："accaccacc"
 *
 *
 * 示例 3：
 *
 *
 * 输入：s = "2[abc]3[cd]ef"
 * 输出："abcabccdcdcdef"
 *
 *
 * 示例 4：
 *
 *
 * 输入：s = "abc3[cd]xyz"
 * 输出："abccdcdcdxyz"
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length <= 30
 * s 由小写英文字母、数字和方括号 '[]' 组成
 * s 保证是一个 有效 的输入。
 * s 中所有整数的取值范围为 [1, 300] 
 *
 *
 */

// @lc code=start
// 栈实现
class Solution {
public:
  string decodeString(string s) {
    stack<pair<string, int>> memory_stack;
    int cur_count = 0;
    string cur_str = "";

    for (const auto c : s) {
      if (isdigit(c)) {
        cur_count = cur_count * 10 + (c - '0');
      } else if (isalpha(c)) {
        cur_str += c;
      } else if (c == '[') {
        memory_stack.push({cur_str, cur_count});
        cur_count = 0;
        cur_str = "";
      } else {
        string pre_str = memory_stack.top().first;
        int k = memory_stack.top().second;
        memory_stack.pop();

        for (size_t i = 0; i < k; ++i) {
          pre_str += cur_str;
        }

        cur_str = pre_str;
      }
    }

    return cur_str;
  }
};
// @lc code=end
