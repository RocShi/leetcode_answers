/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 *
 * https://leetcode.cn/problems/edit-distance/description/
 *
 * algorithms
 * Medium (62.82%)
 * Likes:    3292
 * Dislikes: 0
 * Total Accepted:    439.2K
 * Total Submissions: 698.9K
 * Testcase Example:  '"horse"\n"ros"'
 *
 * 给你两个单词 word1 和 word2， 请返回将 word1 转换成 word2 所使用的最少操作数
 *  。
 *
 * 你可以对一个单词进行如下三种操作：
 *
 *
 * 插入一个字符
 * 删除一个字符
 * 替换一个字符
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：word1 = "horse", word2 = "ros"
 * 输出：3
 * 解释：
 * horse -> rorse (将 'h' 替换为 'r')
 * rorse -> rose (删除 'r')
 * rose -> ros (删除 'e')
 *
 *
 * 示例 2：
 *
 *
 * 输入：word1 = "intention", word2 = "execution"
 * 输出：5
 * 解释：
 * intention -> inention (删除 't')
 * inention -> enention (将 'i' 替换为 'e')
 * enention -> exention (将 'n' 替换为 'x')
 * exention -> exection (将 'n' 替换为 'c')
 * exection -> execution (插入 'u')
 *
 *
 *
 *
 * 提示：
 *
 *
 * 0 <= word1.length, word2.length <= 500
 * word1 和 word2 由小写英文字母组成
 *
 *
 */

// @lc code=start
// 二维动态规划求解
class Solution {
public:
  int minDistance(string word1, string word2) {
    int len1 = word1.size(), len2 = word2.size();
    vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));

    for (int i = 0; i <= len1; ++i) {
      dp.at(i).front() = i;
    }

    for (int j = 0; j <= len2; ++j) {
      dp.front().at(j) = j;
    }

    for (int i = 1; i <= len1; ++i) {
      for (int j = 1; j <= len2; ++j) {
        if (word1.at(i - 1) == word2.at(j - 1)) {
          dp.at(i).at(j) = dp.at(i - 1).at(j - 1);
        } else {
          dp.at(i).at(j) = min(dp.at(i - 1).at(j - 1),
                               min(dp.at(i - 1).at(j), dp.at(i).at(j - 1))) +
                           1;
        }
      }
    }

    return dp.back().back();
  }
};
// @lc code=end
