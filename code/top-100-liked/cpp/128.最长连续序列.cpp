/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 *
 * https://leetcode.cn/problems/longest-consecutive-sequence/description/
 *
 * algorithms
 * Medium (52.64%)
 * Likes:    1968
 * Dislikes: 0
 * Total Accepted:    531.9K
 * Total Submissions: 1M
 * Testcase Example:  '[100,4,200,1,3,2]'
 *
 * 给定一个未排序的整数数组 nums
 * ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。
 *
 * 请你设计并实现时间复杂度为 O(n) 的算法解决此问题。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [100,4,200,1,3,2]
 * 输出：4
 * 解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。
 *
 * 示例 2：
 *
 *
 * 输入：nums = [0,3,7,2,5,8,4,6,0,1]
 * 输出：9
 *
 *
 *
 *
 * 提示：
 *
 *
 * 0
 * -10^9
 *
 *
 */

// @lc code=start
// set 去重排序 + 双指针，找出双指针的最大跨度
class Solution {
public:
  int longestConsecutive(vector<int> &nums) {
    int result = nums.empty() ? 0 : 1;

    if (nums.size() > 1) {
      set<int> values_set;
      for (const auto val : nums) {
        values_set.insert(val);
      }

      vector<int> new_nums;
      new_nums.reserve(values_set.size());
      for (const auto &val : values_set) {
        new_nums.emplace_back(val);
      }

      int slow_idx = 0, fast_idx = 1;
      while (fast_idx < new_nums.size()) {
        if (new_nums.at(fast_idx) - new_nums.at(fast_idx - 1) > 1) {
          result = max(result, fast_idx - slow_idx);
          slow_idx = fast_idx;
        }
        ++fast_idx;
      }

      result = max(result, fast_idx - slow_idx);
    }

    return result;
  }
};
// @lc code=end
