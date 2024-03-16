/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为 K 的子数组
 *
 * https://leetcode.cn/problems/subarray-sum-equals-k/description/
 *
 * algorithms
 * Medium (44.37%)
 * Likes:    2240
 * Dislikes: 0
 * Total Accepted:    399.5K
 * Total Submissions: 900.6K
 * Testcase Example:  '[1,1,1]\n2'
 *
 * 给你一个整数数组 nums 和一个整数 k ，请你统计并返回
 * 该数组中和为 k 的子数组的个数 。
 *
 * 子数组是数组中元素的连续非空序列。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [1,1,1], k = 2
 * 输出：2
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [1,2,3], k = 3
 * 输出：2
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 2 * 10^4
 * -1000 <= nums[i] <= 1000
 * -10^7 <= k <= 10^7
 *
 *
 */

// @lc code=start
// 前缀和求解，对前缀和进行计数
class Solution {
public:
  int subarraySum(vector<int> &nums, int k) {
    int result = 0, pre_sum = 0;
    unordered_map<int, int> pre_sum_counter;
    pre_sum_counter.insert({0, 1});

    for (const int num : nums) {
      pre_sum += num;
      auto iter = pre_sum_counter.find(pre_sum - k);
      if (iter != pre_sum_counter.end()) {
        result += iter->second;
      }
      ++pre_sum_counter[pre_sum];
    }

    return result;
  }
};
// @lc code=end
