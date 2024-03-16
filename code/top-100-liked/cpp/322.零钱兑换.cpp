/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 *
 * https://leetcode.cn/problems/coin-change/description/
 *
 * algorithms
 * Medium (47.30%)
 * Likes:    2702
 * Dislikes: 0
 * Total Accepted:    737.9K
 * Total Submissions: 1.6M
 * Testcase Example:  '[1,2,5]\n11'
 *
 * 给你一个整数数组 coins ，表示不同面额的硬币；以及一个整数 amount
 * ，表示总金额。
 *
 * 计算并返回可以凑成总金额所需的 最少的硬币个数
 * 。如果没有任何一种硬币组合能组成总金额，返回 -1 。
 *
 * 你可以认为每种硬币的数量是无限的。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：coins = [1, 2, 5], amount = 11
 * 输出：3
 * 解释：11 = 5 + 5 + 1
 *
 * 示例 2：
 *
 *
 * 输入：coins = [2], amount = 3
 * 输出：-1
 *
 * 示例 3：
 *
 *
 * 输入：coins = [1], amount = 0
 * 输出：0
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= coins.length <= 12
 * 1 <= coins[i] <= 2^31 - 1
 * 0 <= amount <= 10^4
 *
 *
 */

// @lc code=start
// 动态规划实现
class Solution {
public:
  int coinChange(vector<int> &coins, int amount) {
    vector<int> dp(amount + 1, numeric_limits<int>::max());
    dp.front() = 0;

    for (int i = 1; i < amount + 1; ++i) {
      for (const int coin : coins) {
        if (i - coin >= 0 && dp.at(i - coin) < numeric_limits<int>::max()) {
          dp.at(i) = min(dp.at(i), dp.at(i - coin) + 1);
        }
      }
    }

    return dp.back() < numeric_limits<int>::max() ? dp.back() : -1;
  }
};
// @lc code=end
