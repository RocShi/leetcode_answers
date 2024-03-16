/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 *
 * https://leetcode.cn/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (66.26%)
 * Likes:    3435
 * Dislikes: 0
 * Total Accepted:    1.6M
 * Total Submissions: 2.4M
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * 将两个升序链表合并为一个新的 升序
 * 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：l1 = [1,2,4], l2 = [1,3,4]
 * 输出：[1,1,2,3,4,4]
 *
 *
 * 示例 2：
 *
 *
 * 输入：l1 = [], l2 = []
 * 输出：[]
 *
 *
 * 示例 3：
 *
 *
 * 输入：l1 = [], l2 = [0]
 * 输出：[0]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 两个链表的节点数目范围是 [0, 50]
 * -100
 * l1 和 l2 均按 非递减顺序 排列
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
class Solution {
public:
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    ListNode dummy(0);
    ListNode *p = &dummy, *p1 = list1, *p2 = list2;

    while (p1 != nullptr && p2 != nullptr) {
      if (p1->val <= p2->val) {
        p->next = p1;
        p1 = p1->next;
      } else {
        p->next = p2;
        p2 = p2->next;
      }

      p = p->next;
    }

    if (p1 != nullptr) {
      p->next = p1;
    }

    if (p2 != nullptr) {
      p->next = p2;
    }

    return dummy.next;
  }
};
// @lc code=end
