/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 *
 * https://leetcode.cn/problems/rotate-image/description/
 *
 * algorithms
 * Medium (75.51%)
 * Likes:    1808
 * Dislikes: 0
 * Total Accepted:    527.6K
 * Total Submissions: 698.5K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * 给定一个 n × n 的二维矩阵 matrix 表示一个图像。请你将图像顺时针旋转 90 度。
 *
 * 你必须在 原地 旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要
 * 使用另一个矩阵来旋转图像。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
 * 输出：[[7,4,1],[8,5,2],[9,6,3]]
 *
 *
 * 示例 2：
 *
 *
 * 输入：matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
 * 输出：[[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
 *
 *
 *
 *
 * 提示：
 *
 *
 * n == matrix.length == matrix[i].length
 * 1 <= n <= 20
 * -1000 <= matrix[i][j] <= 1000
 *
 *
 *
 *
 */

// @lc code=start
// 先沿主对角线对矩阵进行转置操作，再对转置后的矩阵关于垂直方向进行镜像
class Solution {
public:
  void rotate(vector<vector<int>> &matrix) {
    int n = matrix.size();

    for (int i = 0; i < n - 1; ++i) {
      for (int j = i + 1; j < n; ++j) {
        swap(matrix.at(i).at(j), matrix.at(j).at(i));
      }
    }

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n / 2; ++j) {
        swap(matrix.at(i).at(j), matrix.at(i).at(n - 1 - j));
      }
    }
  }
};
// @lc code=end
