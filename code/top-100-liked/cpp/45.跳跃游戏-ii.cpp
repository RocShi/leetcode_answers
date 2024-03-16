/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 *
 * https://leetcode.cn/problems/jump-game-ii/description/
 *
 * algorithms
 * Medium (44.66%)
 * Likes:    2436
 * Dislikes: 0
 * Total Accepted:    623.3K
 * Total Submissions: 1.4M
 * Testcase Example:  '[2,3,1,1,4]'
 *
 * 给定一个长度为 n 的 0 索引整数数组 nums。初始位置为 nums[0]。
 *
 * 每个元素 nums[i] 表示从索引 i 向前跳转的最大长度。换句话说，如果你在 nums[i]
 * 处，你可以跳转到任意 nums[i + j] 处:
 *
 *
 * 0 <= j <= nums[i] 
 * i + j < n
 *
 *
 * 返回到达 nums[n - 1] 的最小跳跃次数。生成的测试用例可以到达 nums[n - 1]。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: nums = [2,3,1,1,4]
 * 输出: 2
 * 解释: 跳到最后一个位置的最小跳跃数是 2。
 * 从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。
 *
 *
 * 示例 2:
 *
 *
 * 输入: nums = [2,3,0,1,4]
 * 输出: 2
 *
 *
 *
 *
 * 提示:
 *
 *
 * 1 <= nums.length <= 10^4
 * 0 <= nums[i] <= 1000
 * 题目保证可以到达 nums[n-1]
 *
 *
 */

// @lc code=start
// 贪心实现，到达上一步跳跃的最大可达位置后，就要再跳一步，每一步跳跃的最大可达位置通过
// 遍历数组不断更新
class Solution {
public:
  int jump(vector<int> &nums) {
    int steps = 0, cur_max_reached_idx = 0, next_max_reached_idx = 0;

    for (int i = 0; i < nums.size() - 1; ++i) {
      next_max_reached_idx = max(next_max_reached_idx, i + nums.at(i));
      if (i == cur_max_reached_idx) {
        cur_max_reached_idx = next_max_reached_idx;
        ++steps;
      }
    }

    return steps;
  }
};
// @lc code=end
