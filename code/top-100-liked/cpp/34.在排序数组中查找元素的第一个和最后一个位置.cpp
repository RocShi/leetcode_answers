/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 *
 * https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 *
 * algorithms
 * Medium (42.98%)
 * Likes:    2620
 * Dislikes: 0
 * Total Accepted:    916.4K
 * Total Submissions: 2.1M
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * 给你一个按照非递减顺序排列的整数数组 nums，和一个目标值
 * target。请你找出给定目标值在数组中的开始位置和结束位置。
 *
 * 如果数组中不存在目标值 target，返回 [-1, -1]。
 *
 * 你必须设计并实现时间复杂度为 O(log n) 的算法解决此问题。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [5,7,7,8,8,10], target = 8
 * 输出：[3,4]
 *
 * 示例 2：
 *
 *
 * 输入：nums = [5,7,7,8,8,10], target = 6
 * 输出：[-1,-1]
 *
 * 示例 3：
 *
 *
 * 输入：nums = [], target = 0
 * 输出：[-1,-1]
 *
 *
 *
 * 提示：
 *
 *
 * 0 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 * nums 是一个非递减数组
 * -10^9 <= target <= 10^9
 *
 *
 */

// @lc code=start
// 二分法实现，分别寻找左右边界
class Solution {
public:
  vector<int> searchRange(vector<int> &nums, int target) {
    vector<int> result = {-1, -1};

    if (!nums.empty()) {
      int left_idx = 0, right_idx = nums.size() - 1;
      while (left_idx < right_idx) {
        int mid_idx = left_idx + (right_idx - left_idx) / 2;
        if (nums.at(mid_idx) < target) {
          left_idx = mid_idx + 1;
        } else if (nums.at(mid_idx) > target) {
          right_idx = mid_idx - 1;
        } else {
          right_idx = mid_idx;
        }
      }
      if (nums.at(left_idx) == target) {
        result.front() = left_idx;
      } else {
        return result;
      }

      right_idx = nums.size() - 1;
      while (left_idx < right_idx) {
        int mid_idx = left_idx + (right_idx - left_idx) / 2 + 1;
        if (nums.at(mid_idx) < target) {
          left_idx = mid_idx + 1;
        } else if (nums.at(mid_idx) > target) {
          right_idx = mid_idx - 1;
        } else {
          left_idx = mid_idx;
        }
      }
      result.back() = right_idx;
    }

    return result;
  }
};
// @lc code=end
