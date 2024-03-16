/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 *
 * https://leetcode.cn/problems/sliding-window-maximum/description/
 *
 * algorithms
 * Hard (49.05%)
 * Likes:    2693
 * Dislikes: 0
 * Total Accepted:    546.3K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,3,-1,-3,5,3,6,7]\n3'
 *
 * 给你一个整数数组
 * nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的
 * k 个数字。滑动窗口每次只向右移动一位。
 *
 * 返回 滑动窗口中的最大值 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
 * 输出：[3,3,5,5,6,7]
 * 解释：
 * 滑动窗口的位置                最大值
 * ---------------               -----
 * [1  3  -1] -3  5  3  6  7       3
 * ⁠1 [3  -1  -3] 5  3  6  7       3
 * ⁠1  3 [-1  -3  5] 3  6  7       5
 * ⁠1  3  -1 [-3  5  3] 6  7       5
 * ⁠1  3  -1  -3 [5  3  6] 7       6
 * ⁠1  3  -1  -3  5 [3  6  7]      7
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [1], k = 1
 * 输出：[1]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 * 1 <= k <= nums.length
 *
 *
 */

// @lc code=start
// 单调队列（从队首到队尾遵循非严格单调递减策略）实现
class MonotonicQueue {
private:
  deque<int> max_queue_;

public:
  MonotonicQueue(/* args */) = default;
  ~MonotonicQueue() = default;

  void pushBack(int num) {
    while (!max_queue_.empty() && max_queue_.back() < num) {
      max_queue_.pop_back();
    }
    max_queue_.push_back(num);
  }

  void popFront(int num) {
    if (num == max_queue_.front()) {
      max_queue_.pop_front();
    }
  }

  int getMax() { return max_queue_.front(); }
};

class Solution {
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    vector<int> result;
    result.reserve(nums.size() - k + 1);
    MonotonicQueue window;

    for (size_t i = 0; i < nums.size(); ++i) {
      window.pushBack(nums.at(i));
      if (i >= k - 1) {
        result.emplace_back(window.getMax());
        window.popFront(nums.at(i - k + 1));
      }
    }

    return result;
  }
};

// @lc code=end
