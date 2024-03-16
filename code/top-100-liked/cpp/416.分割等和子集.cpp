/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 *
 * https://leetcode.cn/problems/partition-equal-subset-sum/description/
 *
 * algorithms
 * Medium (52.33%)
 * Likes:    2001
 * Dislikes: 0
 * Total Accepted:    496.5K
 * Total Submissions: 948.5K
 * Testcase Example:  '[1,5,11,5]'
 *
 * 给你一个 只包含正整数 的 非空 数组 nums
 * 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [1,5,11,5]
 * 输出：true
 * 解释：数组可以分割成 [1, 5, 5] 和 [11] 。
 *
 * 示例 2：
 *
 *
 * 输入：nums = [1,2,3,5]
 * 输出：false
 * 解释：数组不能分割成两个元素和相等的子集。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * 1
 *
 *
 */

// @lc code=start
// 问题转化为：数组中是否存在子集的和为数组所有元素和的一半
// 二维动态规划实现，dp[i][j] 表示 nums 的前 i 个数字中是否存在子集的和为
// j，应注意的是，第 i 个数字为 nums[i - 1]
class Solution {
public:
  bool canPartition(vector<int> &nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 != 0) {
      return false;
    }

    int m = nums.size(), n = sum / 2;
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
    for (auto &row : dp) {
      row.front() = true;
    }

    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (nums.at(i - 1) > j) {
          dp.at(i).at(j) = dp.at(i - 1).at(j);
        } else {
          dp.at(i).at(j) =
              dp.at(i - 1).at(j) || dp.at(i - 1).at(j - nums.at(i - 1));
        }
      }
    }

    return dp.back().back();
  }
};
// @lc code=end
