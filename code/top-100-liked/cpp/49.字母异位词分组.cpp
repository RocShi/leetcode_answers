// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem49.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 *
 * https://leetcode.cn/problems/group-anagrams/description/
 *
 * algorithms
 * Medium (67.83%)
 * Likes:    1810
 * Dislikes: 0
 * Total Accepted:    605.1K
 * Total Submissions: 892.1K
 * Testcase Example:  '["eat","tea","tan","ate","nat","bat"]'
 *
 * 给你一个字符串数组，请你将 字母异位词
 * 组合在一起。可以按任意顺序返回结果列表。
 *
 * 字母异位词 是由重新排列源单词的所有字母得到的一个新单词。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
 * 输出: [["bat"],["nat","tan"],["ate","eat","tea"]]
 *
 * 示例 2:
 *
 *
 * 输入: strs = [""]
 * 输出: [[""]]
 *
 *
 * 示例 3:
 *
 *
 * 输入: strs = ["a"]
 * 输出: [["a"]]
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= strs.length <= 10^4
 * 0 <= strs[i].length <= 100
 * strs[i] 仅包含小写字母
 *
 *
 */

// @lc code=start
// 字符串排序 + 哈希表
class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    vector<vector<string>> result;
    unordered_map<string, vector<string>> groups;

    for (const string &str : strs) {
      string key = str;
      sort(key.begin(), key.end());
      groups[key].emplace_back(str);
    }

    for (auto iter = groups.begin(); iter != groups.end(); ++iter) {
      result.emplace_back(iter->second);
    }

    return result;
  }
};
// @lc code=end
