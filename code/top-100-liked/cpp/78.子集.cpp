/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 *
 * https://leetcode.cn/problems/subsets/description/
 *
 * algorithms
 * Medium (81.20%)
 * Likes:    2242
 * Dislikes: 0
 * Total Accepted:    727.2K
 * Total Submissions: 895.4K
 * Testcase Example:  '[1,2,3]'
 *
 * 给你一个整数数组 nums ，数组中的元素 互不相同
 * 。返回该数组所有可能的子集（幂集）。
 *
 * 解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [1,2,3]
 * 输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [0]
 * 输出：[[],[0]]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * -10
 * nums 中的所有元素 互不相同
 *
 *
 */

// @lc code=start
// 回溯实现
class Solution {
public:
  vector<vector<int>> subsets(vector<int> &nums) {
    vector<vector<int>> result;
    vector<int> path;
    backtrack(nums, result, path, 0);
    return result;
  }

  void backtrack(const vector<int> &nums, vector<vector<int>> &result,
                 vector<int> &path, int start_idx) {
    result.emplace_back(path);

    for (int i = start_idx; i < nums.size(); ++i) {
      path.emplace_back(nums.at(i));
      backtrack(nums, result, path, i + 1);
      path.pop_back();
    }
  }
};
// @lc code=end
