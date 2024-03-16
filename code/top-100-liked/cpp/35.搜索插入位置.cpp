/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 *
 * https://leetcode.cn/problems/search-insert-position/description/
 *
 * algorithms
 * Easy (45.70%)
 * Likes:    2256
 * Dislikes: 0
 * Total Accepted:    1.3M
 * Total Submissions: 2.9M
 * Testcase Example:  '[1,3,5,6]\n5'
 *
 * 给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
 *
 * 请必须使用时间复杂度为 O(log n) 的算法。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: nums = [1,3,5,6], target = 5
 * 输出: 2
 *
 *
 * 示例 2:
 *
 *
 * 输入: nums = [1,3,5,6], target = 2
 * 输出: 1
 *
 *
 * 示例 3:
 *
 *
 * 输入: nums = [1,3,5,6], target = 7
 * 输出: 4
 *
 *
 *
 *
 * 提示:
 *
 *
 * 1 <= nums.length <= 10^4
 * -10^4 <= nums[i] <= 10^4
 * nums 为 无重复元素 的 升序 排列数组
 * -10^4 <= target <= 10^4
 *
 *
 */

// @lc code=start
// 二分法实现
class Solution {
public:
  int searchInsert(vector<int> &nums, int target) {
    if (target < nums.front()) {
      return 0;
    } else if (target > nums.back()) {
      return nums.size();
    } else {
      int left_idx = 0, right_idx = nums.size() - 1;

      while (left_idx < right_idx) {
        int mid_idx = left_idx + (right_idx - left_idx) / 2;
        if (nums.at(mid_idx) < target) {
          left_idx = mid_idx + 1;
        } else if (nums.at(mid_idx) > target) {
          right_idx = mid_idx;
        } else {
          return mid_idx;
        }
      }

      return left_idx;
    }
  }
};
// @lc code=end
