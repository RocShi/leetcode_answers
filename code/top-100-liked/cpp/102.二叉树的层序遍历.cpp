/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
 *
 * https://leetcode.cn/problems/binary-tree-level-order-traversal/description/
 *
 * algorithms
 * Medium (66.47%)
 * Likes:    1878
 * Dislikes: 0
 * Total Accepted:    951.9K
 * Total Submissions: 1.4M
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给你二叉树的根节点 root ，返回其节点值的 层序遍历 。
 * （即逐层地，从左到右访问所有节点）。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：root = [3,9,20,null,null,15,7]
 * 输出：[[3],[9,20],[15,7]]
 *
 *
 * 示例 2：
 *
 *
 * 输入：root = [1]
 * 输出：[[1]]
 *
 *
 * 示例 3：
 *
 *
 * 输入：root = []
 * 输出：[]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中节点数目在范围 [0, 2000] 内
 * -1000 <= Node.val <= 1000
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
// BFS，使用 queue 辅助
class Solution {
public:
  vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> result;

    if (root != nullptr) {
      queue<TreeNode *> nodes_queue;
      nodes_queue.push(root);
      int level_nodes_num = 1;
      vector<int> level_nodes_val;

      while (!nodes_queue.empty()) {
        level_nodes_num = nodes_queue.size();
        level_nodes_val.clear();
        level_nodes_val.reserve(level_nodes_num);

        for (size_t i = 0; i < level_nodes_num; ++i) {
          level_nodes_val.emplace_back(nodes_queue.front()->val);

          if (nodes_queue.front()->left != nullptr) {
            nodes_queue.push(nodes_queue.front()->left);
          }

          if (nodes_queue.front()->right != nullptr) {
            nodes_queue.push(nodes_queue.front()->right);
          }

          nodes_queue.pop();
        }

        result.emplace_back(level_nodes_val);
      }
    }

    return result;
  }
};
// @lc code=end
