/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 *
 * https://leetcode.cn/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (77.57%)
 * Likes:    3516
 * Dislikes: 0
 * Total Accepted:    790.6K
 * Total Submissions: 1M
 * Testcase Example:  '3'
 *
 * 数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且
 * 有效的 括号组合。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：n = 3
 * 输出：["((()))","(()())","(())()","()(())","()()()"]
 *
 *
 * 示例 2：
 *
 *
 * 输入：n = 1
 * 输出：["()"]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= n <= 8
 *
 *
 */

// @lc code=start
// 回溯实现
class Solution {
public:
  vector<string> generateParenthesis(int n) {
    vector<string> result;
    string path;
    backtrack(result, path, n, 0, 0);
    return result;
  }

  void backtrack(vector<string> &result, string &path, int n,
                 int used_left_nums, int used_right_nums) {
    if (path.size() == 2 * n) {
      result.emplace_back(path);
      return;
    }

    if (used_left_nums < n) {
      path.push_back('(');
      backtrack(result, path, n, used_left_nums + 1, used_right_nums);
      path.pop_back();
    }

    if (used_right_nums < used_left_nums) {
      path.push_back(')');
      backtrack(result, path, n, used_left_nums, used_right_nums + 1);
      path.pop_back();
    }
  }
};
// @lc code=end
