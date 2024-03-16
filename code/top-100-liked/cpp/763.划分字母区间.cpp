/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 *
 * https://leetcode.cn/problems/partition-labels/description/
 *
 * algorithms
 * Medium (76.80%)
 * Likes:    1097
 * Dislikes: 0
 * Total Accepted:    205.6K
 * Total Submissions: 267.7K
 * Testcase Example:  '"ababcbacadefegdehijhklij"'
 *
 * 给你一个字符串 s
 * 。我们要把这个字符串划分为尽可能多的片段，同一字母最多出现在一个片段中。
 *
 * 注意，划分结果需要满足：将所有划分结果按顺序连接，得到的字符串仍然是 s 。
 *
 * 返回一个表示每个字符串片段的长度的列表。
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = "ababcbacadefegdehijhklij"
 * 输出：[9,7,8]
 * 解释：
 * 划分结果为 "ababcbaca"、"defegde"、"hijhklij" 。
 * 每个字母最多出现在一个片段中。
 * 像 "ababcbacadefegde", "hijhklij" 这样的划分是错误的，因为划分的片段数较少。
 *
 * 示例 2：
 *
 *
 * 输入：s = "eccbbbbdec"
 * 输出：[10]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length <= 500
 * s 仅由小写英文字母组成
 *
 *
 */

// @lc code=start
class Solution {
public:
  vector<int> partitionLabels(string s) {
    vector<int> result;
    unordered_map<char, size_t> max_indices_map;
    for (size_t i = 0; i < s.size(); ++i) {
      max_indices_map[s.at(i)] = i;
    }

    size_t start_idx = 0, cur_max_idx = 0;
    for (size_t i = 0; i < s.size(); ++i) {
      cur_max_idx = max(cur_max_idx, max_indices_map.at(s.at(i)));
      if (i == cur_max_idx) {
        result.emplace_back(i - start_idx + 1);
        start_idx = i + 1;
      }
    }

    return result;
  }
};
// @lc code=end
