/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 *
 * https://leetcode.cn/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (41.93%)
 * Likes:    7008
 * Dislikes: 0
 * Total Accepted:    1.1M
 * Total Submissions: 2.5M
 * Testcase Example:  '[1,3]\n[2]'
 *
 * 给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1
 * 和 nums2。请你找出并返回这两个正序数组的 中位数 。
 *
 * 算法的时间复杂度应该为 O(log (m+n)) 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums1 = [1,3], nums2 = [2]
 * 输出：2.00000
 * 解释：合并数组 = [1,2,3] ，中位数 2
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums1 = [1,2], nums2 = [3,4]
 * 输出：2.50000
 * 解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5
 *
 *
 *
 *
 *
 *
 * 提示：
 *
 *
 * nums1.length == m
 * nums2.length == n
 * 0 <= m <= 1000
 * 0 <= n <= 1000
 * 1 <= m + n <= 2000
 * -10^6 <= nums1[i], nums2[i] <= 10^6
 *
 *
 */

// @lc code=start
// 二分法实现，关键在于递归查找第 k 小的数
class Solution {
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    size_t len1 = nums1.size(), len2 = nums2.size();
    size_t total_len = len1 + len2;

    if (total_len % 2 == 1) {
      return findKthNum(nums1, 0, len1, nums2, 0, len2, total_len / 2 + 1);
    } else {
      return (findKthNum(nums1, 0, len1, nums2, 0, len2, total_len / 2) +
              findKthNum(nums1, 0, len1, nums2, 0, len2, total_len / 2 + 1)) /
             2.0;
    }
  }

  double findKthNum(const vector<int> &nums1, size_t start1, size_t end1,
                    const vector<int> &nums2, size_t start2, size_t end2,
                    size_t k) {
    size_t len1 = end1 - start1, len2 = end2 - start2;
    if (len1 > len2) {
      return findKthNum(nums2, start2, end2, nums1, start1, end1, k);
    }

    if (len1 == 0) {
      return nums2.at(start2 + k - 1);
    }

    if (k == 1) {
      return min(nums1.at(start1), nums2.at(start2));
    }

    size_t idx1 = min(end1 - 1, start1 + k / 2 - 1);
    size_t idx2 = min(end2 - 1, start2 + k / 2 - 1);

    if (nums1.at(idx1) < nums2.at(idx2)) {
      return findKthNum(nums1, idx1 + 1, end1, nums2, start2, end2,
                        k - (idx1 - start1 + 1));
    } else {
      return findKthNum(nums1, start1, end1, nums2, idx2 + 1, end2,
                        k - (idx2 - start2 + 1));
    }
  }
};
// @lc code=end
