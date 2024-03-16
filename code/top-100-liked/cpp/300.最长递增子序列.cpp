/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 *
 * https://leetcode.cn/problems/longest-increasing-subsequence/description/
 *
 * algorithms
 * Medium (55.40%)
 * Likes:    3559
 * Dislikes: 0
 * Total Accepted:    863.5K
 * Total Submissions: 1.6M
 * Testcase Example:  '[10,9,2,5,3,7,101,18]'
 *
 * 给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。
 *
 * 子序列 是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，[3,6,2,7]
 * 是数组 [0,3,1,6,2,2,7] 的子序列。
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [10,9,2,5,3,7,101,18]
 * 输出：4
 * 解释：最长递增子序列是 [2,3,7,101]，因此长度为 4 。
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [0,1,0,3,2,3]
 * 输出：4
 *
 *
 * 示例 3：
 *
 *
 * 输入：nums = [7,7,7,7,7,7,7]
 * 输出：1
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 2500
 * -10^4 <= nums[i] <= 10^4
 *
 *
 *
 *
 * 进阶：
 *
 *
 * 你能将算法的时间复杂度降低到 O(n log(n)) 吗?
 *
 *
 */

// @lc code=start
// 动态规划实现，dp[i] 表示以 nums[i] 结尾的最长递增子序列的长度
class Solution {
public:
  int lengthOfLIS(vector<int> &nums) {
    int result = 0;
    vector<int> dp(nums.size(), 1);

    for (size_t i = 0; i < nums.size(); ++i) {
      for (size_t j = 0; j < i; ++j) {
        if (nums.at(j) < nums.at(i)) {
          dp.at(i) = max(dp.at(i), dp.at(j) + 1);
        }
      }
      result = max(result, dp.at(i));
    }

    return result;
  }
};
// @lc code=end
