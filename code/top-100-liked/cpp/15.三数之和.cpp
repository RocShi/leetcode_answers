/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 *
 * https://leetcode.cn/problems/3sum/description/
 *
 * algorithms
 * Medium (37.65%)
 * Likes:    6674
 * Dislikes: 0
 * Total Accepted:    1.6M
 * Total Submissions: 4.4M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * 给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i
 * != j、i != k 且 j != k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。请
 *
 * 你返回所有和为 0 且不重复的三元组。
 *
 * 注意：答案中不可以包含重复的三元组。
 *
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [-1,0,1,2,-1,-4]
 * 输出：[[-1,-1,2],[-1,0,1]]
 * 解释：
 * nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0 。
 * nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0 。
 * nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0 。
 * 不同的三元组是 [-1,0,1] 和 [-1,-1,2] 。
 * 注意，输出的顺序和三元组的顺序并不重要。
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [0,1,1]
 * 输出：[]
 * 解释：唯一可能的三元组和不为 0 。
 *
 *
 * 示例 3：
 *
 *
 * 输入：nums = [0,0,0]
 * 输出：[[0,0,0]]
 * 解释：唯一可能的三元组和为 0 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 3 <= nums.length <= 3000
 * -10^5 <= nums[i] <= 10^5
 *
 *
 */

// @lc code=start
// 两数之和的变种，双指针 + 剪枝实现，关键在于去重策略
class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    int sum = 0, left_idx = 0, right_idx = 0;

    for (int i = 0; i < nums.size() - 2; ++i) {
      if (i > 0 && nums.at(i) == nums.at(i - 1)) {
        continue;
      }

      left_idx = i + 1;
      right_idx = nums.size() - 1;
      while (left_idx < right_idx) {
        sum = nums.at(i) + nums.at(left_idx) + nums.at(right_idx);
        if (sum < 0) {
          ++left_idx;
        } else if (sum > 0) {
          --right_idx;
        } else {
          result.emplace_back(
              vector<int>{nums.at(i), nums.at(left_idx), nums.at(right_idx)});
          ++left_idx;
          --right_idx;

          while (left_idx < right_idx &&
                 nums.at(left_idx) == nums.at(left_idx - 1)) {
            ++left_idx;
          }

          while (left_idx < right_idx &&
                 nums.at(right_idx) == nums.at(right_idx + 1)) {
            --right_idx;
          }
        }
      }
    }

    return result;
  }
};
// @lc code=end
