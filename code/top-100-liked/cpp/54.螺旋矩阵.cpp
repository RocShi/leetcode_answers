/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 *
 * https://leetcode.cn/problems/spiral-matrix/description/
 *
 * algorithms
 * Medium (50.16%)
 * Likes:    1596
 * Dislikes: 0
 * Total Accepted:    457.4K
 * Total Submissions: 911.2K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * 给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序
 * ，返回矩阵中的所有元素。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
 * 输出：[1,2,3,6,9,8,7,4,5]
 *
 *
 * 示例 2：
 *
 *
 * 输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
 * 输出：[1,2,3,4,8,12,11,10,9,5,6,7]
 *
 *
 *
 *
 * 提示：
 *
 *
 * m == matrix.length
 * n == matrix[i].length
 * 1
 * -100
 *
 *
 */

// @lc code=start
class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>> &matrix) {
    vector<int> result;
    int m = matrix.size(), n = matrix.front().size(), elements_num = m * n;
    int row_idx_upper_bound = 0, row_idx_lower_bound = m - 1;
    int col_idx_left_bound = 0, col_idx_right_bound = n - 1;

    while (result.size() < elements_num) {
      for (int i = col_idx_left_bound;
           i <= col_idx_right_bound && result.size() < elements_num; ++i) {
        result.emplace_back(matrix.at(row_idx_upper_bound).at(i));
      }
      ++row_idx_upper_bound;

      for (int i = row_idx_upper_bound;
           i <= row_idx_lower_bound && result.size() < elements_num; ++i) {
        result.emplace_back(matrix.at(i).at(col_idx_right_bound));
      }
      --col_idx_right_bound;

      for (int i = col_idx_right_bound;
           i >= col_idx_left_bound && result.size() < elements_num; --i) {
        result.emplace_back(matrix.at(row_idx_lower_bound).at(i));
      }
      --row_idx_lower_bound;

      for (int i = row_idx_lower_bound;
           i >= row_idx_upper_bound && result.size() < elements_num; --i) {
        result.emplace_back(matrix.at(i).at(col_idx_left_bound));
      }
      ++col_idx_left_bound;
    }

    return result;
  }
};
// @lc code=end
