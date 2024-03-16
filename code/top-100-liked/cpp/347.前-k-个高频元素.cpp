/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 *
 * https://leetcode.cn/problems/top-k-frequent-elements/description/
 *
 * algorithms
 * Medium (63.57%)
 * Likes:    1782
 * Dislikes: 0
 * Total Accepted:    505.7K
 * Total Submissions: 795.6K
 * Testcase Example:  '[1,1,1,2,2,3]\n2'
 *
 * 给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k
 * 高的元素。你可以按 任意顺序 返回答案。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: nums = [1,1,1,2,2,3], k = 2
 * 输出: [1,2]
 *
 *
 * 示例 2:
 *
 *
 * 输入: nums = [1], k = 1
 * 输出: [1]
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * k 的取值范围是 [1, 数组中不相同的元素的个数]
 * 题目数据保证答案唯一，换句话说，数组中前 k 个高频元素的集合是唯一的
 *
 *
 *
 *
 * 进阶：你所设计算法的时间复杂度 必须 优于 O(n log n) ，其中 n 是数组大小。
 *
 */

// @lc code=start
// 小根堆实现，堆中存储的是频率及对应数字组成的 pair
class Solution {
  typedef pair<int, int> INT_PAIR;

public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
    unordered_map<int, int> freq_map;
    for (const int num : nums) {
      ++freq_map[num];
    }

    priority_queue<INT_PAIR, vector<INT_PAIR>, greater<INT_PAIR>> min_heap;
    for (auto iter = freq_map.begin(); iter != freq_map.end(); ++iter) {
      min_heap.push({iter->second, iter->first});
      if (min_heap.size() > k) {
        min_heap.pop();
      }
    }

    vector<int> result;
    result.reserve(k);
    while (!min_heap.empty()) {
      result.emplace_back(min_heap.top().second);
      min_heap.pop();
    }

    return result;
  }
};
// @lc code=end
