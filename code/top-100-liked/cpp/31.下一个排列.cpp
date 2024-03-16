/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 *
 * https://leetcode.cn/problems/next-permutation/description/
 *
 * algorithms
 * Medium (38.85%)
 * Likes:    2424
 * Dislikes: 0
 * Total Accepted:    485K
 * Total Submissions: 1.2M
 * Testcase Example:  '[1,2,3]'
 *
 * 整数数组的一个 排列  就是将其所有成员以序列或线性顺序排列。
 *
 *
 * 例如，arr = [1,2,3] ，以下这些都可以视作 arr
 * 的排列：[1,2,3]、[1,3,2]、[3,1,2]、[2,3,1] 。
 *
 *
 * 整数数组的 下一个排列
 * 是指其整数的下一个字典序更大的排列。更正式地，如果数组的所有排列根据其字典顺序从小到大排列在一个容器中，那么数组的
 * 下一个排列
 * 就是在这个有序容器中排在它后面的那个排列。如果不存在下一个更大的排列，那么这个数组必须重排为字典序最小的排列（即，其元素按升序排列）。
 *
 *
 * 例如，arr = [1,2,3] 的下一个排列是 [1,3,2] 。
 * 类似地，arr = [2,3,1] 的下一个排列是 [3,1,2] 。
 * 而 arr = [3,2,1] 的下一个排列是 [1,2,3] ，因为 [3,2,1]
 * 不存在一个字典序更大的排列。
 *
 *
 * 给你一个整数数组 nums ，找出 nums 的下一个排列。
 *
 * 必须 原地 修改，只允许使用额外常数空间。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [1,2,3]
 * 输出：[1,3,2]
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [3,2,1]
 * 输出：[1,2,3]
 *
 *
 * 示例 3：
 *
 *
 * 输入：nums = [1,1,5]
 * 输出：[1,5,1]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 100
 * 0 <= nums[i] <= 100
 *
 *
 */

// @lc code=start
// 三步实现：
//     1. 逆序查找第一个降序元素对，将该降序元素对的左元素索引记为 i
//     2. 在 i 的右侧逆序查找第一个大于 i 号元素的元素，将找到的元素索引记为
//        j，并交换 i 号元素和 j 号元素
//     3. 反转 i 号元素右侧的所有元素
class Solution {
public:
  void nextPermutation(vector<int> &nums) {
    int i = nums.size() - 2;
    while (i >= 0 && nums.at(i + 1) <= nums.at(i)) {
      --i;
    }

    int j = nums.size() - 1;
    if (i >= 0) {
      while (j > i && nums.at(j) <= nums.at(i)) {
        --j;
      }
      swap(nums.at(i), nums.at(j));
    }

    reverse(nums.begin() + i + 1, nums.end());
  }
};
// @lc code=end
