/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
 *
 * https://leetcode.cn/problems/sort-list/description/
 *
 * algorithms
 * Medium (65.51%)
 * Likes:    2238
 * Dislikes: 0
 * Total Accepted:    467.7K
 * Total Submissions: 713.8K
 * Testcase Example:  '[4,2,1,3]'
 *
 * 给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。
 *
 *
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：head = [4,2,1,3]
 * 输出：[1,2,3,4]
 *
 *
 * 示例 2：
 *
 *
 * 输入：head = [-1,5,3,4,0]
 * 输出：[-1,0,3,4,5]
 *
 *
 * 示例 3：
 *
 *
 * 输入：head = []
 * 输出：[]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 链表中节点的数目在范围 [0, 5 * 10^4] 内
 * -10^5 <= Node.val <= 10^5
 *
 *
 *
 *
 * 进阶：你可以在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序吗？
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
// 基于分治的思想，使用归并排序实现。主要思路包含三点：
// 1. 使用两倍速快慢指针寻找链表中点，将链表一分为二
// 2. 递归排序分割得到的两个链表
// 3. 合并两个排序后的链表，即“21.合并两个有序链表”
class Solution {
public:
  ListNode *sortList(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }

    ListNode *mid = searchMiddleNode(head);
    ListNode *right_half_head = mid->next;
    mid->next = nullptr;

    ListNode *sorted_left = sortList(head);
    ListNode *sorted_right = sortList(right_half_head);

    return mergeSortedLists(sorted_left, sorted_right);
  }

  ListNode *searchMiddleNode(ListNode *head) {
    ListNode *slow_node = head;
    ListNode *fast_node = head->next;

    while (fast_node != nullptr && fast_node->next != nullptr) {
      slow_node = slow_node->next;
      fast_node = fast_node->next->next;
    }

    return slow_node;
  }

  ListNode *mergeSortedLists(ListNode *list1, ListNode *list2) {
    ListNode dummy(0);
    ListNode *tail = &dummy;
    ListNode *p1 = list1;
    ListNode *p2 = list2;

    while (p1 != nullptr && p2 != nullptr) {
      if (p1->val < p2->val) {
        tail->next = p1;
        p1 = p1->next;
      } else {
        tail->next = p2;
        p2 = p2->next;
      }
      tail = tail->next;
    }

    if (p1 != nullptr) {
      tail->next = p1;
    }

    if (p2 != nullptr) {
      tail->next = p2;
    }

    return dummy.next;
  }
};
// @lc code=end
