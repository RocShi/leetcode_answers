/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
 *
 * https://leetcode.cn/problems/palindrome-linked-list/description/
 *
 * algorithms
 * Easy (53.95%)
 * Likes:    1858
 * Dislikes: 0
 * Total Accepted:    685.2K
 * Total Submissions: 1.3M
 * Testcase Example:  '[1,2,2,1]'
 *
 * 给你一个单链表的头节点 head ，请你判断该链表是否为回文链表。如果是，返回 true
 * ；否则，返回 false 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：head = [1,2,2,1]
 * 输出：true
 *
 *
 * 示例 2：
 *
 *
 * 输入：head = [1,2]
 * 输出：false
 *
 *
 *
 *
 * 提示：
 *
 *
 * 链表中节点数目在范围[1, 10^5] 内
 * 0 <= Node.val <= 9
 *
 *
 *
 *
 * 进阶：你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？
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
// 将链表元素存入 vector，检查 vector 是否对称，时间复杂度 O(n)，空间复杂度 O(n)
class Solution {
public:
  bool isPalindrome(ListNode *head) {
    ListNode *p = head;
    vector<int> vec;
    while (p != nullptr) {
      vec.emplace_back(p->val);
      p = p->next;
    }

    int left_idx = 0, right_idx = vec.size() - 1;
    while (left_idx < right_idx) {
      if (vec.at(left_idx) != vec.at(right_idx)) {
        return false;
      }
      ++left_idx;
      --right_idx;
    }

    return true;
  }
};
// @lc code=end
