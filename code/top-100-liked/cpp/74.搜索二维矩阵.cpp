/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 *
 * https://leetcode.cn/problems/search-a-2d-matrix/description/
 *
 * algorithms
 * Medium (49.29%)
 * Likes:    895
 * Dislikes: 0
 * Total Accepted:    364.3K
 * Total Submissions: 738.9K
 * Testcase Example:  '[[1,3,5,7],[10,11,16,20],[23,30,34,60]]\n3'
 *
 * 给你一个满足下述两条属性的 m x n 整数矩阵：
 *
 *
 * 每行中的整数从左到右按非严格递增顺序排列。
 * 每行的第一个整数大于前一行的最后一个整数。
 *
 *
 * 给你一个整数 target ，如果 target 在矩阵中，返回 true ；否则，返回 false 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
 * 输出：true
 *
 *
 * 示例 2：
 *
 *
 * 输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
 * 输出：false
 *
 *
 *
 *
 * 提示：
 *
 *
 * m == matrix.length
 * n == matrix[i].length
 * 1 <= m, n <= 100
 * -10^4 <= matrix[i][j], target <= 10^4
 *
 *
 */

// @lc code=start
// 二分查找，将顺序索引转换为矩阵元素坐标
class Solution {
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int rows_num = matrix.size();
    int cols_num = matrix.front().size();
    int left_idx = 0, right_idx = rows_num * cols_num - 1;

    while (left_idx <= right_idx) {
      int mid_idx = left_idx + (right_idx - left_idx) / 2;
      int row_idx = mid_idx / cols_num;
      int col_idx = mid_idx % cols_num;

      if (matrix.at(row_idx).at(col_idx) < target) {
        left_idx = mid_idx + 1;
      } else if (matrix.at(row_idx).at(col_idx) > target) {
        right_idx = mid_idx - 1;
      } else {
        return true;
      }
    }

    return false;
  }
};
// @lc code=end
