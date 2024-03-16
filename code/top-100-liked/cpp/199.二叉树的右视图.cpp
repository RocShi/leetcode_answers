/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
 *
 * https://leetcode.cn/problems/binary-tree-right-side-view/description/
 *
 * algorithms
 * Medium (66.54%)
 * Likes:    1027
 * Dislikes: 0
 * Total Accepted:    364K
 * Total Submissions: 546.9K
 * Testcase Example:  '[1,2,3,null,5,null,4]'
 *
 * 给定一个二叉树的 根节点
 * root，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。
 *
 *
 *
 * 示例 1:
 *
 *
 *
 *
 * 输入: [1,2,3,null,5,null,4]
 * 输出: [1,3,4]
 *
 *
 * 示例 2:
 *
 *
 * 输入: [1,null,3]
 * 输出: [1,3]
 *
 *
 * 示例 3:
 *
 *
 * 输入: []
 * 输出: []
 *
 *
 *
 *
 * 提示:
 *
 *
 * 二叉树的节点个数的范围是 [0,100]
 * -100  
 *
 *
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
// 层序遍历，记录每一层的最后一个节点值
class Solution {
public:
  vector<int> rightSideView(TreeNode *root) {
    vector<int> result;

    if (root != nullptr) {
      queue<TreeNode *> nodes_queue;
      nodes_queue.push(root);
      size_t level_nodes_num = 1;

      while (!nodes_queue.empty()) {
        level_nodes_num = nodes_queue.size();

        for (size_t i = 0; i < level_nodes_num; ++i) {
          if (nodes_queue.front()->left != nullptr) {
            nodes_queue.push(nodes_queue.front()->left);
          }

          if (nodes_queue.front()->right != nullptr) {
            nodes_queue.push(nodes_queue.front()->right);
          }

          if (i == level_nodes_num - 1) {
            result.emplace_back(nodes_queue.front()->val);
          }

          nodes_queue.pop();
        }
      }
    }

    return result;
  }
};
// @lc code=end
