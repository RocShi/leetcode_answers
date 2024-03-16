/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 *
 * https://leetcode.cn/problems/largest-rectangle-in-histogram/description/
 *
 * algorithms
 * Hard (45.43%)
 * Likes:    2659
 * Dislikes: 0
 * Total Accepted:    389.4K
 * Total Submissions: 856.9K
 * Testcase Example:  '[2,1,5,6,2,3]'
 *
 * 给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为
 * 1 。
 *
 * 求在该柱状图中，能够勾勒出来的矩形的最大面积。
 *
 *
 *
 * 示例 1:
 *
 *
 *
 *
 * 输入：heights = [2,1,5,6,2,3]
 * 输出：10
 * 解释：最大的矩形为图中红色区域，面积为 10
 *
 *
 * 示例 2：
 *
 *
 *
 *
 * 输入： heights = [2,4]
 * 输出： 4
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * 0
 *
 *
 */

// @lc code=start
// 单调栈 + 双哨兵节点实现，哨兵节点用于处理两侧边界
class Solution {
public:
  int largestRectangleArea(vector<int> &heights) {
    int result = 0;
    stack<int> indices_stack;
    heights.insert(heights.begin(), 0);
    heights.emplace_back(0);

    for (int i = 0; i < heights.size(); ++i) {
      while (!indices_stack.empty() &&
             heights.at(i) < heights.at(indices_stack.top())) {
        auto height_idx = indices_stack.top();
        indices_stack.pop();
        auto width = i - indices_stack.top() - 1;
        auto height = heights.at(height_idx);
        result = max(result, width * height);
      }
      indices_stack.push(i);
    }

    return result;
  }
};
// @lc code=end
