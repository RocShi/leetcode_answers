/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子数组
 *
 * https://leetcode.cn/problems/maximum-product-subarray/description/
 *
 * algorithms
 * Medium (43.16%)
 * Likes:    2179
 * Dislikes: 0
 * Total Accepted:    404.7K
 * Total Submissions: 937.5K
 * Testcase Example:  '[2,3,-2,4]'
 *
 * 给你一个整数数组
 * nums ，请你找出数组中乘积最大的非空连续子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积。
 *
 * 测试用例的答案是一个 32-位 整数。
 *
 * 子数组 是数组的连续子序列。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: nums = [2,3,-2,4]
 * 输出: 6
 * 解释: 子数组 [2,3] 有最大乘积 6。
 *
 *
 * 示例 2:
 *
 *
 * 输入: nums = [-2,0,-1]
 * 输出: 0
 * 解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。
 *
 *
 *
 * 提示:
 *
 *
 * 1 <= nums.length <= 2 * 10^4
 * -10 <= nums[i] <= 10
 * nums 的任何前缀或后缀的乘积都 保证 是一个 32-位 整数
 *
 *
 */

// @lc code=start
// 动态规划实现，使用四个动态变量：
// dp_max_cur：以 nums 当前数字为结尾的子数组的最大乘积
// dp_max_last：以 nums 上一个数字为结尾的子数组的最大乘积
// dp_min_cur：以 nums 当前数字为结尾的子数组的最小乘积
// dp_min_last：以 nums 上一个数字为结尾的子数组的最小乘积
class Solution {
public:
  int maxProduct(vector<int> &nums) {
    int result = nums.front();
    int dp_max_cur = nums.front(), dp_max_last = nums.front();
    int dp_min_cur = nums.front(), dp_min_last = nums.front();

    for (size_t i = 1; i < nums.size(); ++i) {
      if (nums.at(i) > 0) {
        dp_max_cur = max(nums.at(i), dp_max_last * nums.at(i));
        dp_min_cur = min(nums.at(i), dp_min_last * nums.at(i));
      } else {
        dp_max_cur = max(nums.at(i), dp_min_last * nums.at(i));
        dp_min_cur = min(nums.at(i), dp_max_last * nums.at(i));
      }

      result = max(result, dp_max_cur);
      dp_max_last = dp_max_cur;
      dp_min_last = dp_min_cur;
    }

    return result;
  }
};
// @lc code=end
