/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 *
 * https://leetcode.cn/problems/perfect-squares/description/
 *
 * algorithms
 * Medium (66.49%)
 * Likes:    1905
 * Dislikes: 0
 * Total Accepted:    474.1K
 * Total Submissions: 712.7K
 * Testcase Example:  '12'
 *
 * 给你一个整数 n ，返回 和为 n 的完全平方数的最少数量 。
 *
 * 完全平方数
 * 是一个整数，其值等于另一个整数的平方；换句话说，其值等于一个整数自乘的积。例如，1、4、9
 * 和 16 都是完全平方数，而 3 和 11 不是。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：n = 12
 * 输出：3
 * 解释：12 = 4 + 4 + 4
 *
 * 示例 2：
 *
 *
 * 输入：n = 13
 * 输出：2
 * 解释：13 = 4 + 9
 *
 *
 * 提示：
 *
 *
 * 1 <= n <= 10^4
 *
 *
 */

// @lc code=start
// 动态规划求解
class Solution {
public:
  int numSquares(int n) {
    vector<int> dp(n + 1, numeric_limits<int>::max());
    dp.front() = 0;

    for (int i = 1; i < n + 1; ++i) {
      for (int j = 1; j * j <= i; ++j) {
        dp.at(i) = min(dp.at(i), dp.at(i - j * j) + 1);
      }
    }

    return dp.back();
  }
};
// @lc code=end
