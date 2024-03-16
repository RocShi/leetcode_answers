/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 *
 * https://leetcode.cn/problems/trapping-rain-water/description/
 *
 * algorithms
 * Hard (63.23%)
 * Likes:    5007
 * Dislikes: 0
 * Total Accepted:    857.7K
 * Total Submissions: 1.4M
 * Testcase Example:  '[0,1,0,2,1,0,1,3,2,1,2,1]'
 *
 * 给定 n 个非负整数表示每个宽度为 1
 * 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 *
 * 输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
 * 输出：6
 * 解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1]
 * 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。
 *
 *
 * 示例 2：
 *
 *
 * 输入：height = [4,2,0,3,2,5]
 * 输出：9
 *
 *
 *
 *
 * 提示：
 *
 *
 * n == height.length
 * 1 <= n <= 2 * 10^4
 * 0 <= height[i] <= 10^5
 *
 *
 */

// @lc code=start
// 左右双指针实现
class Solution {
public:
  int trap(vector<int> &height) {
    int result = 0;
    int left_idx = 0, right_idx = height.size() - 1;
    int left_max_h = 0, right_max_h = 0;

    while (left_idx < right_idx) {
      left_max_h = max(left_max_h, height.at(left_idx));
      right_max_h = max(right_max_h, height.at(right_idx));

      if (left_max_h < right_max_h) {
        result += (left_max_h - height.at(left_idx));
        ++left_idx;
      } else {
        result += (right_max_h - height.at(right_idx));
        --right_idx;
      }
    }

    return result;
  }
};
// @lc code=end
