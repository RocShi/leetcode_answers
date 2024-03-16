/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
 *
 * https://leetcode.cn/problems/diameter-of-binary-tree/description/
 *
 * algorithms
 * Easy (59.51%)
 * Likes:    1475
 * Dislikes: 0
 * Total Accepted:    378K
 * Total Submissions: 635.1K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * 给你一棵二叉树的根节点，返回该树的 直径 。
 *
 * 二叉树的 直径 是指树中任意两个节点之间最长路径的 长度
 * 。这条路径可能经过也可能不经过根节点 root 。
 *
 * 两节点之间路径的 长度 由它们之间边数表示。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：root = [1,2,3,4,5]
 * 输出：3
 * 解释：3 ，取路径 [4,2,1,3] 或 [5,2,1,3] 的长度。
 *
 *
 * 示例 2：
 *
 *
 * 输入：root = [1,2]
 * 输出：1
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中节点数目在范围 [1, 10^4] 内
 * -100 <= Node.val <= 100
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
// 树的最大深度问题的变种
// 当前根节点的左子树最大深度 + 当前根节点的右子树最大深度 =
// 以当前节点为中转的最长路径长度
class Solution {
public:
  int diameterOfBinaryTree(TreeNode *root) {
    if (root != nullptr) {
      int d_root = traverse(root->left) + traverse(root->right);
      return max(max(d_root, diameterOfBinaryTree(root->left)),
                 diameterOfBinaryTree(root->right));
    } else {
      return 0;
    }
  }

  int traverse(TreeNode *root) {
    if (root != nullptr) {
      return 1 + max(traverse(root->left), traverse(root->right));
    } else {
      return 0;
    }
  }
};
// @lc code=end
