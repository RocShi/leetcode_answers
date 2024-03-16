/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 *
 * https://leetcode.cn/problems/pascals-triangle/description/
 *
 * algorithms
 * Easy (75.60%)
 * Likes:    1119
 * Dislikes: 0
 * Total Accepted:    477.8K
 * Total Submissions: 631.8K
 * Testcase Example:  '5'
 *
 * 给定一个非负整数 numRows，生成「杨辉三角」的前 numRows 行。
 *
 * 在「杨辉三角」中，每个数是它左上方和右上方的数的和。
 *
 *
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: numRows = 5
 * 输出: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
 *
 *
 * 示例 2:
 *
 *
 * 输入: numRows = 1
 * 输出: [[1]]
 *
 *
 *
 *
 * 提示:
 *
 *
 * 1
 *
 *
 */

// @lc code=start
class Solution {
public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> result(numRows, vector<int>());

    for (int i = 0; i < numRows; ++i) {
      result.at(i).resize(i + 1, 1);
      for (int j = 1; j < i; ++j) {
        result.at(i).at(j) =
            result.at(i - 1).at(j - 1) + result.at(i - 1).at(j);
      }
    }

    return result;
  }
};
// @lc code=end
