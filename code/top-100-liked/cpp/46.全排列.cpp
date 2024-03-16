/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 *
 * https://leetcode.cn/problems/permutations/description/
 *
 * algorithms
 * Medium (79.03%)
 * Likes:    2812
 * Dislikes: 0
 * Total Accepted:    999.3K
 * Total Submissions: 1.3M
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序
 * 返回答案。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [1,2,3]
 * 输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [0,1]
 * 输出：[[0,1],[1,0]]
 *
 *
 * 示例 3：
 *
 *
 * 输入：nums = [1]
 * 输出：[[1]]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 6
 * -10 <= nums[i] <= 10
 * nums 中的所有整数 互不相同
 *
 *
 */

// @lc code=start
// 回溯实现
class Solution {
public:
  vector<vector<int>> permute(vector<int> &nums) {
    vector<vector<int>> result;
    vector<int> path;
    vector<bool> used_flags(nums.size(), false);
    backtrack(nums, used_flags, result, path);
    return result;
  }

  void backtrack(const vector<int> &nums, vector<bool> &used_flags,
                 vector<vector<int>> &result, vector<int> &path) {
    if (path.size() == nums.size()) {
      result.emplace_back(path);
      return;
    }

    for (size_t i = 0; i < nums.size(); ++i) {
      if (used_flags.at(i)) {
        continue;
      }

      path.emplace_back(nums.at(i));
      used_flags.at(i) = true;
      backtrack(nums, used_flags, result, path);
      used_flags.at(i) = false;
      path.pop_back();
    }
  }
};
// @lc code=end
