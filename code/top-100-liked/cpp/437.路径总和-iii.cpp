/*
 * @lc app=leetcode.cn id=437 lang=cpp
 *
 * [437] 路径总和 III
 *
 * https://leetcode.cn/problems/path-sum-iii/description/
 *
 * algorithms
 * Medium (48.66%)
 * Likes:    1796
 * Dislikes: 0
 * Total Accepted:    270.1K
 * Total Submissions: 555.3K
 * Testcase Example:  '[10,5,-3,3,2,null,11,3,-2,null,1]\n8'
 *
 * 给定一个二叉树的根节点 root ，和一个整数 targetSum
 * ，求该二叉树里节点值之和等于 targetSum 的 路径 的数目。
 *
 * 路径
 * 不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 *
 * 输入：root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
 * 输出：3
 * 解释：和等于 8 的路径有 3 条，如图所示。
 *
 *
 * 示例 2：
 *
 *
 * 输入：root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
 * 输出：3
 *
 *
 *
 *
 * 提示:
 *
 *
 * 二叉树的节点个数的范围是 [0,1000]
 * -10^9  
 * -1000  
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
// 递归实现：以当前节点为起点的路径和 + 左子树的路径和 + 右子树的路径和
class Solution {
public:
  int pathSum(TreeNode *root, int targetSum) {
    if (root != nullptr) {
      return traversal(root, targetSum) + pathSum(root->left, targetSum) +
             pathSum(root->right, targetSum);
    } else {
      return 0;
    }
  }

  int traversal(TreeNode *root, long targetSum) {
    if (root != nullptr) {
      int result = 0;
      if (root->val == targetSum) {
        ++result;
      }
      return result + traversal(root->left, targetSum - root->val) +
             traversal(root->right, targetSum - root->val);
    } else {
      return 0;
    }
  }
};
// @lc code=end
