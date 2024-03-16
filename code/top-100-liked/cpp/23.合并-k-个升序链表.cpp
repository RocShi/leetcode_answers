/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并 K 个升序链表
 *
 * https://leetcode.cn/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (58.90%)
 * Likes:    2757
 * Dislikes: 0
 * Total Accepted:    755.6K
 * Total Submissions: 1.3M
 * Testcase Example:  '[[1,4,5],[1,3,4],[2,6]]'
 *
 * 给你一个链表数组，每个链表都已经按升序排列。
 *
 * 请你将所有链表合并到一个升序链表中，返回合并后的链表。
 *
 *
 *
 * 示例 1：
 *
 * 输入：lists = [[1,4,5],[1,3,4],[2,6]]
 * 输出：[1,1,2,3,4,4,5,6]
 * 解释：链表数组如下：
 * [
 * ⁠ 1->4->5,
 * ⁠ 1->3->4,
 * ⁠ 2->6
 * ]
 * 将它们合并到一个有序链表中得到。
 * 1->1->2->3->4->4->5->6
 *
 *
 * 示例 2：
 *
 * 输入：lists = []
 * 输出：[]
 *
 *
 * 示例 3：
 *
 * 输入：lists = [[]]
 * 输出：[]
 *
 *
 *
 *
 * 提示：
 *
 *
 * k == lists.length
 * 0 <= k <= 10^4
 * 0 <= lists[i].length <= 500
 * -10^4 <= lists[i][j] <= 10^4
 * lists[i] 按 升序 排列
 * lists[i].length 的总和不超过 10^4
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
// 小根堆实现，堆的节点即链表头节点，由于所有链表都按升序排列，所以小根堆的根节点的节点
// 值在当前尚未被合并的所有节点中最小
// 也可以基于分治的思想，将所有链表分组两两合并，两个链表合并即“21.合并两个有序链表”
class Solution {
public:
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    auto NodeComparator = [](ListNode *a, ListNode *b) -> bool {
      return a->val > b->val;
    };

    priority_queue<ListNode *, vector<ListNode *>, decltype(NodeComparator)>
        nodes_min_heap(NodeComparator);

    for (auto node : lists) {
      if (node != nullptr) {
        nodes_min_heap.push(node);
      }
    }

    ListNode dummy(0);
    ListNode *p = &dummy;
    while (!nodes_min_heap.empty()) {
      auto node = nodes_min_heap.top();
      nodes_min_heap.pop();
      p->next = node;
      p = p->next;

      if (node->next != nullptr) {
        nodes_min_heap.push(node->next);
      }
    }

    return dummy.next;
  }
};
// @lc code=end
