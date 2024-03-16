/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 *
 * https://leetcode.cn/problems/n-queens/description/
 *
 * algorithms
 * Hard (73.94%)
 * Likes:    2030
 * Dislikes: 0
 * Total Accepted:    366.4K
 * Total Submissions: 495.5K
 * Testcase Example:  '4'
 *
 * 按照国际象棋的规则，皇后可以攻击与之处在同一行或同一列或同一斜线上的棋子。
 *
 * n 皇后问题 研究的是如何将 n 个皇后放置在 n×n
 * 的棋盘上，并且使皇后彼此之间不能相互攻击。
 *
 * 给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。
 *
 *
 *
 * 每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.'
 * 分别代表了皇后和空位。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：n = 4
 * 输出：[[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
 * 解释：如上图所示，4 皇后问题存在两个不同的解法。
 *
 *
 * 示例 2：
 *
 *
 * 输入：n = 1
 * 输出：[["Q"]]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= n <= 9
 *
 *
 *·
 *
 */

// @lc code=start
// 回溯实现
class Solution {
public:
  vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> result;
    vector<string> path;
    backtrack(result, path, n, 0);
    return result;
  }

  void backtrack(vector<vector<string>> &result, vector<string> &path, int n,
                 int row_idx) {
    if (path.size() == n) {
      result.emplace_back(path);
      return;
    }

    for (int i = 0; i < n; ++i) {
      if (isValid(path, n, i)) {
        string sub_path(n, '.');
        sub_path.at(i) = 'Q';
        path.emplace_back(sub_path);
        backtrack(result, path, n, row_idx + 1);
        path.pop_back();
      }
    }
  }

  bool isValid(const vector<string> &path, int n, int col_idx) {
    for (int row_idx = path.size() - 1; row_idx >= 0; --row_idx) {
      int left_diag_col_idx = col_idx - (path.size() - row_idx);
      int right_diag_col_idx = col_idx + (path.size() - row_idx);

      // column check, left diagonal check, right diagonal check
      if (path.at(row_idx).at(col_idx) == 'Q' ||
          (left_diag_col_idx >= 0 &&
           path.at(row_idx).at(left_diag_col_idx) == 'Q') ||
          (right_diag_col_idx < n &&
           path.at(row_idx).at(right_diag_col_idx) == 'Q')) {
        return false;
      }
    }

    return true;
  }
};
// @lc code=end
