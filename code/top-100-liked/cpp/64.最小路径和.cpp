/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 *
 * https://leetcode.cn/problems/minimum-path-sum/description/
 *
 * algorithms
 * Medium (69.96%)
 * Likes:    1635
 * Dislikes: 0
 * Total Accepted:    557.5K
 * Total Submissions: 796.5K
 * Testcase Example:  '[[1,3,1],[1,5,1],[4,2,1]]'
 *
 * 给定一个包含非负整数的 m x n 网格 grid
 * ，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
 *
 * 说明：每次只能向下或者向右移动一步。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：grid = [[1,3,1],[1,5,1],[4,2,1]]
 * 输出：7
 * 解释：因为路径 1→3→1→1→1 的总和最小。
 *
 *
 * 示例 2：
 *
 *
 * 输入：grid = [[1,2,3],[4,5,6]]
 * 输出：12
 *
 *
 *
 *
 * 提示：
 *
 *
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 200
 * 0 <= grid[i][j] <= 200
 *
 *
 */

// @lc code=start
// 二维动态规划，和“62.不同路径”很相似
class Solution {
public:
  int minPathSum(vector<vector<int>> &grid) {
    size_t rows_num = grid.size();
    size_t cols_num = grid.front().size();
    vector<vector<int>> dp = grid;

    for (size_t i = 1; i < rows_num; ++i) {
      dp.at(i).front() += dp.at(i - 1).front();
    }

    for (size_t j = 1; j < cols_num; ++j) {
      dp.front().at(j) += dp.front().at(j - 1);
    }

    for (size_t i = 1; i < rows_num; ++i) {
      for (size_t j = 1; j < cols_num; ++j) {
        dp.at(i).at(j) += min(dp.at(i - 1).at(j), dp.at(i).at(j - 1));
      }
    }

    return dp.back().back();
  }
};
// @lc code=end
