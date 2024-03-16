/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 *
 * https://leetcode.cn/problems/number-of-islands/description/
 *
 * algorithms
 * Medium (60.03%)
 * Likes:    2417
 * Dislikes: 0
 * Total Accepted:    760.6K
 * Total Submissions: 1.3M
 * Testcase Example:
 * '[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]'
 *
 * 给你一个由 '1'（陆地）和
 * '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
 *
 * 岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。
 *
 * 此外，你可以假设该网格的四条边均被水包围。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：grid = [
 * ⁠ ["1","1","1","1","0"],
 * ⁠ ["1","1","0","1","0"],
 * ⁠ ["1","1","0","0","0"],
 * ⁠ ["0","0","0","0","0"]
 * ]
 * 输出：1
 *
 *
 * 示例 2：
 *
 *
 * 输入：grid = [
 * ⁠ ["1","1","0","0","0"],
 * ⁠ ["1","1","0","0","0"],
 * ⁠ ["0","0","1","0","0"],
 * ⁠ ["0","0","0","1","1"]
 * ]
 * 输出：3
 *
 *
 *
 *
 * 提示：
 *
 *
 * m == grid.length
 * n == grid[i].length
 * 1
 * grid[i][j] 的值为 '0' 或 '1'
 *
 *
 */

// @lc code=start
// 通过 dfs 将所有相连的陆地“淹没”
class Solution {
private:
  int rows_num = 0;
  int cols_num = 0;

public:
  int numIslands(vector<vector<char>> &grid) {
    int result = 0;
    rows_num = static_cast<int>(grid.size());
    cols_num = static_cast<int>(grid.front().size());

    for (int i = 0; i < rows_num; ++i) {
      for (int j = 0; j < cols_num; ++j) {
        if (grid.at(i).at(j) == '1') {
          ++result;
          dfs(grid, i, j);
        }
      }
    }

    return result;
  }

  void dfs(vector<vector<char>> &grid, int i, int j) {
    if (i >= 0 && i < rows_num && j >= 0 && j < cols_num &&
        grid.at(i).at(j) == '1') {
      grid.at(i).at(j) = '0';

      dfs(grid, i - 1, j);
      dfs(grid, i + 1, j);
      dfs(grid, i, j - 1);
      dfs(grid, i, j + 1);
    }
  }
};
// @lc code=end
