/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 *
 * https://leetcode.cn/problems/word-search/description/
 *
 * algorithms
 * Medium (46.64%)
 * Likes:    1766
 * Dislikes: 0
 * Total Accepted:    486.5K
 * Total Submissions: 1M
 * Testcase Example:
 * '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
 *
 * 给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word
 * 存在于网格中，返回 true ；否则，返回 false 。
 *
 * 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word =
 * "ABCCED"
 * 输出：true
 *
 *
 * 示例 2：
 *
 *
 * 输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word =
 * "SEE"
 * 输出：true
 *
 *
 * 示例 3：
 *
 *
 * 输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word =
 * "ABCB"
 * 输出：false
 *
 *
 *
 *
 * 提示：
 *
 *
 * m == board.length
 * n = board[i].length
 * 1
 * 1
 * board 和 word 仅由大小写英文字母组成
 *
 *
 *
 *
 * 进阶：你可以使用搜索剪枝的技术来优化解决方案，使其在 board
 * 更大的情况下可以更快解决问题？
 *
 */

// @lc code=start
// 深度优先搜索实现，很有趣的题目，搜索的过程类似“走迷宫”
class Solution {
public:
  bool exist(vector<vector<char>> &board, string word) {
    int m = board.size(), n = board.front().size();
    vector<vector<bool>> used_flags(m, vector<bool>(n, false));

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (dfs(board, word, used_flags, m, n, i, j, 0)) {
          return true;
        }
      }
    }

    return false;
  }

  bool dfs(const vector<vector<char>> &board, const string &word,
           vector<vector<bool>> &used_flags, int m, int n, int row_idx,
           int col_idx, int letter_idx) {
    if (row_idx < 0 || row_idx >= m || col_idx < 0 || col_idx >= n ||
        used_flags.at(row_idx).at(col_idx) ||
        board.at(row_idx).at(col_idx) != word.at(letter_idx)) {
      return false;
    }

    if (letter_idx == word.size() - 1) {
      return true;
    }

    used_flags.at(row_idx).at(col_idx) = true;
    bool result = dfs(board, word, used_flags, m, n, row_idx - 1, col_idx,
                      letter_idx + 1) ||
                  dfs(board, word, used_flags, m, n, row_idx + 1, col_idx,
                      letter_idx + 1) ||
                  dfs(board, word, used_flags, m, n, row_idx, col_idx - 1,
                      letter_idx + 1) ||
                  dfs(board, word, used_flags, m, n, row_idx, col_idx + 1,
                      letter_idx + 1);
    used_flags.at(row_idx).at(col_idx) = false;

    return result;
  }
};
// @lc code=end
