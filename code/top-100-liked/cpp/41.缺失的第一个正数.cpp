/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 *
 * https://leetcode.cn/problems/first-missing-positive/description/
 *
 * algorithms
 * Hard (43.88%)
 * Likes:    2055
 * Dislikes: 0
 * Total Accepted:    352.1K
 * Total Submissions: 801.6K
 * Testcase Example:  '[1,2,0]'
 *
 * 给你一个未排序的整数数组 nums ，请你找出其中没有出现的最小的正整数。
 * 请你实现时间复杂度为 O(n) 并且只使用常数级别额外空间的解决方案。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [1,2,0]
 * 输出：3
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [3,4,-1,1]
 * 输出：2
 *
 *
 * 示例 3：
 *
 *
 * 输入：nums = [7,8,9,11,12]
 * 输出：1
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * -2^31
 *
 *
 */

// @lc code=start
// 两次遍历实现：第一次遍历将原数组中的正整数各归其位；第二次遍历找到的第一个位置与元素
// 不匹配的数即为结果，如果所有位置与元素都匹配，则 n+1 即为结果
class Solution {
public:
  int firstMissingPositive(vector<int> &nums) {
    for (int i = 0; i < nums.size(); ++i) {
      while (nums.at(i) >= 1 && nums.at(i) <= nums.size() &&
             nums.at(nums.at(i) - 1) != nums.at(i)) {
        swap(nums.at(i), nums.at(nums.at(i) - 1));
      }
    }

    for (int i = 0; i < nums.size(); ++i) {
      if (nums.at(i) != i + 1) {
        return i + 1;
      }
    }

    return nums.size() + 1;
  }
};
// @lc code=end
