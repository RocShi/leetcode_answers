/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 *
 * https://leetcode.cn/problems/move-zeroes/description/
 *
 * algorithms
 * Easy (63.51%)
 * Likes:    2298
 * Dislikes: 0
 * Total Accepted:    1.3M
 * Total Submissions: 2M
 * Testcase Example:  '[0,1,0,3,12]'
 *
 * 给定一个数组 nums，编写一个函数将所有 0
 * 移动到数组的末尾，同时保持非零元素的相对顺序。
 *
 * 请注意 ，必须在不复制数组的情况下原地对数组进行操作。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: nums = [0,1,0,3,12]
 * 输出: [1,3,12,0,0]
 *
 *
 * 示例 2:
 *
 *
 * 输入: nums = [0]
 * 输出: [0]
 *
 *
 *
 * 提示:
 *
 *
 *
 * 1 <= nums.length <= 10^4
 * -2^31 <= nums[i] <= 2^31 - 1
 *
 *
 *
 *
 * 进阶：你能尽量减少完成的操作次数吗？
 *
 */

// @lc code=start
// 双指针：慢指针找 0，快指针找非 0
class Solution {
public:
  void moveZeroes(vector<int> &nums) {
    size_t slow_idx = 0, fast_idx = 1;

    while (fast_idx < nums.size()) {
      if (nums.at(slow_idx) == 0) {
        if (nums.at(fast_idx) != 0) {
          swap(nums.at(slow_idx), nums.at(fast_idx));
          ++slow_idx;
        }
      } else {
        ++slow_idx;
      }

      ++fast_idx;
    }
  }
};
// @lc code=end
