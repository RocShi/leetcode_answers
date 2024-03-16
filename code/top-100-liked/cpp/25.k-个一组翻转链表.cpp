/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
 *
 * https://leetcode.cn/problems/reverse-nodes-in-k-group/description/
 *
 * algorithms
 * Hard (67.77%)
 * Likes:    2274
 * Dislikes: 0
 * Total Accepted:    547.6K
 * Total Submissions: 808K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * 给你链表的头节点 head ，每 k 个节点一组进行翻转，请你返回修改后的链表。
 *
 * k
 * 是一个正整数，它的值小于或等于链表的长度。如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
 *
 * 你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：head = [1,2,3,4,5], k = 2
 * 输出：[2,1,4,3,5]
 *
 *
 * 示例 2：
 *
 *
 *
 *
 * 输入：head = [1,2,3,4,5], k = 3
 * 输出：[3,2,1,4,5]
 *
 *
 *
 * 提示：
 *
 *
 * 链表中的节点数目为 n
 * 1 <= k <= n <= 5000
 * 0 <= Node.val <= 1000
 *
 *
 *
 *
 * 进阶：你可以设计一个只用 O(1) 额外内存空间的算法解决此问题吗？
 *
 *
 *
 *
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// 递归实现，重点在于链表的区间翻转 [start, end)
class Solution {
public:
  ListNode *reverseKGroup(ListNode *head, int k) {
    if (head == nullptr || k == 1) {
      return head;
    }

    ListNode *start = head, *end = head;
    for (size_t i = 0; i < k; ++i) {
      if (end == nullptr) {
        return head;
      }
      end = end->next;
    }

    ListNode *new_head = reverseInterval(start, end);
    start->next = reverseKGroup(end, k);

    return new_head;
  }

  ListNode *reverseInterval(ListNode *start, ListNode *end) {
    ListNode *pre_node = nullptr, *cur_node = start, *next_node = nullptr;

    while (cur_node != nullptr && cur_node != end) {
      next_node = cur_node->next;
      cur_node->next = pre_node;
      pre_node = cur_node;
      cur_node = next_node;
    }

    return pre_node;
  }
};
// @lc code=end
