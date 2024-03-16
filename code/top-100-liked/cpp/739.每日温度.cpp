/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 *
 * https://leetcode.cn/problems/daily-temperatures/description/
 *
 * algorithms
 * Medium (68.77%)
 * Likes:    1703
 * Dislikes: 0
 * Total Accepted:    506.7K
 * Total Submissions: 736.7K
 * Testcase Example:  '[73,74,75,71,69,72,76,73]'
 *
 * 给定一个整数数组 temperatures ，表示每天的温度，返回一个数组 answer ，其中 answer[i] 是指对于第
 * i 天，下一个更高温度出现在几天后。如果气温在这之后都不会升高，请在该位置用 0
 * 来代替。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: temperatures = [73,74,75,71,69,72,76,73]
 * 输出: [1,1,4,2,1,1,0,0]
 *
 *
 * 示例 2:
 *
 *
 * 输入: temperatures = [30,40,50,60]
 * 输出: [1,1,1,0]
 *
 *
 * 示例 3:
 *
 *
 * 输入: temperatures = [30,60,90]
 * 输出: [1,1,0]
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= temperatures.length <= 10^5
 * 30 <= temperatures[i] <= 100
 *
 *
 */

// @lc code=start
// 单调栈实现
class Solution {
public:
  vector<int> dailyTemperatures(vector<int> &temperatures) {
    vector<int> result(temperatures.size(), 0);
    stack<int> idx_stack;

    for (int i = temperatures.size() - 1; i >= 0; --i) {
      while (!idx_stack.empty() &&
             temperatures.at(idx_stack.top()) <= temperatures.at(i)) {
        idx_stack.pop();
      }

      if (!idx_stack.empty()) {
        result.at(i) = idx_stack.top() - i;
      }

      idx_stack.push(i);
    }

    return result;
  }
};
// @lc code=end
