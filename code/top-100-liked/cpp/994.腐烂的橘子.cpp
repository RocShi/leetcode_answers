/*
 * @lc app=leetcode.cn id=994 lang=cpp
 *
 * [994] 腐烂的橘子
 *
 * https://leetcode.cn/problems/rotting-oranges/description/
 *
 * algorithms
 * Medium (51.28%)
 * Likes:    807
 * Dislikes: 0
 * Total Accepted:    143K
 * Total Submissions: 278.7K
 * Testcase Example:  '[[2,1,1],[1,1,0],[0,1,1]]'
 *
 * 在给定的 m x n 网格 grid 中，每个单元格可以有以下三个值之一：
 *
 *
 * 值 0 代表空单元格；
 * 值 1 代表新鲜橘子；
 * 值 2 代表腐烂的橘子。
 *
 *
 * 每分钟，腐烂的橘子 周围 4 个方向上相邻 的新鲜橘子都会腐烂。
 *
 * 返回
 * 直到单元格中没有新鲜橘子为止所必须经过的最小分钟数。如果不可能，返回 -1 。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 *
 * 输入：grid = [[2,1,1],[1,1,0],[0,1,1]]
 * 输出：4
 *
 *
 * 示例 2：
 *
 *
 * 输入：grid = [[2,1,1],[0,1,1],[1,0,1]]
 * 输出：-1
 * 解释：左下角的橘子（第 2 行， 第 0 列）永远不会腐烂，因为腐烂只会发生在 4
 * 个方向上。
 *
 *
 * 示例 3：
 *
 *
 * 输入：grid = [[0,2]]
 * 输出：0
 * 解释：因为 0 分钟时已经没有新鲜橘子了，所以答案就是 0 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 10
 * grid[i][j] 仅为 0、1 或 2
 *
 *
 */

// @lc code=start
// 广度优先搜索实现，遍历当前时刻所有已经腐烂的橘子，每个腐烂的橘子分别尝试朝上下左右四
// 个方向进行腐蚀
class Solution {
public:
  int orangesRotting(vector<vector<int>> &grid) {
    int minutes = 0, fresh_oranges_num = 0;
    int rows_num = grid.size();
    int cols_num = grid.front().size();
    queue<pair<int, int>> rotten_oranges_indices;

    for (int i = 0; i < rows_num; ++i) {
      for (int j = 0; j < cols_num; ++j) {
        if (grid.at(i).at(j) == 1) {
          ++fresh_oranges_num;
        } else if (grid.at(i).at(j) == 2) {
          rotten_oranges_indices.push({i, j});
        } else {
          // do nothing
        }
      }
    }

    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    while (!rotten_oranges_indices.empty()) {
      int rotten_oranges_num = rotten_oranges_indices.size();

      for (int i = 0; i < rotten_oranges_num; ++i) {
        const auto raw_indices = rotten_oranges_indices.front();
        rotten_oranges_indices.pop();

        for (const auto &direction : directions) {
          int new_row_idx = raw_indices.first + direction.front();
          int new_col_idx = raw_indices.second + direction.back();

          if (new_row_idx >= 0 && new_row_idx < rows_num && new_col_idx >= 0 &&
              new_col_idx < cols_num &&
              grid.at(new_row_idx).at(new_col_idx) == 1) {
            grid.at(new_row_idx).at(new_col_idx) = 2;
            --fresh_oranges_num;
            rotten_oranges_indices.push({new_row_idx, new_col_idx});
          }
        }
      }

      if (!rotten_oranges_indices.empty()) {
        ++minutes;
      }
    }

    return fresh_oranges_num == 0 ? minutes : -1;
  }
};
// @lc code=end
