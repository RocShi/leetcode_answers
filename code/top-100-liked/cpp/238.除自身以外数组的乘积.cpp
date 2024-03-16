/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 *
 * https://leetcode.cn/problems/product-of-array-except-self/description/
 *
 * algorithms
 * Medium (75.14%)
 * Likes:    1704
 * Dislikes: 0
 * Total Accepted:    373.3K
 * Total Submissions: 496.7K
 * Testcase Example:  '[1,2,3,4]'
 *
 * 给你一个整数数组 nums，返回
 * 数组 answer ，其中 answer[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积 。
 *
 * 题目数据 保证 数组 nums之中任意元素的全部前缀元素和后缀的乘积都在  32 位
 * 整数范围内。
 *
 * 请 不要使用除法，且在 O(n) 时间复杂度内完成此题。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: nums = [1,2,3,4]
 * 输出: [24,12,8,6]
 *
 *
 * 示例 2:
 *
 *
 * 输入: nums = [-1,1,0,-3,3]
 * 输出: [0,0,9,0,0]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 2 <= nums.length <= 10^5
 * -30 <= nums[i] <= 30
 * 保证 数组 nums之中任意元素的全部前缀元素和后缀的乘积都在  32 位 整数范围内
 *
 *
 *
 *
 * 进阶：你可以在 O(1) 的额外空间复杂度内完成这个题目吗？（
 * 出于对空间复杂度分析的目的，输出数组 不被视为 额外空间。）
 *
 */

// @lc code=start
// 类似前缀和的思想：当前元素的前缀积与后缀积的乘积即除自身以外数组的乘积
class Solution {
public:
  vector<int> productExceptSelf(vector<int> &nums) {
    vector<int> result(nums.size(), 1);

    int left_product = 1;
    for (int i = 1; i < nums.size(); ++i) {
      left_product *= nums.at(i - 1);
      result.at(i) = left_product;
    }

    int right_product = 1;
    for (int i = nums.size() - 2; i >= 0; --i) {
      right_product *= nums.at(i + 1);
      result.at(i) *= right_product;
    }

    return result;
  }
};
// @lc code=end
