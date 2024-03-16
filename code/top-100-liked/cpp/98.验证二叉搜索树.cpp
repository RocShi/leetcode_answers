/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
 *
 * https://leetcode.cn/problems/validate-binary-search-tree/description/
 *
 * algorithms
 * Medium (37.54%)
 * Likes:    2265
 * Dislikes: 0
 * Total Accepted:    839K
 * Total Submissions: 2.2M
 * Testcase Example:  '[2,1,3]'
 *
 * 给你一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树。
 *
 * 有效 二叉搜索树定义如下：
 *
 *
 * 节点的左子树只包含 小于 当前节点的数。
 * 节点的右子树只包含 大于 当前节点的数。
 * 所有左子树和右子树自身必须也是二叉搜索树。
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：root = [2,1,3]
 * 输出：true
 *
 *
 * 示例 2：
 *
 *
 * 输入：root = [5,1,4,null,null,3,6]
 * 输出：false
 * 解释：根节点的值是 5 ，但是右子节点的值是 4 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中节点数目范围在[1, 10^4] 内
 * -2^31 <= Node.val <= 2^31 - 1
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
// 一边中序遍历，一边比较当前节点值与已遍历结果末尾值的大小，对于二叉搜索树而言，其中序
// 遍历结果必定是一个单调递增序列
class Solution {
public:
  bool isValidBST(TreeNode *root) {
    vector<int> inorder_vec;
    return traverse(root, inorder_vec);
  }

  bool traverse(TreeNode *root, vector<int> &inorder_vec) {
    if (root == nullptr) {
      return true;
    }

    if (!traverse(root->left, inorder_vec)) {
      return false;
    }

    if (inorder_vec.empty() || inorder_vec.back() < root->val) {
      inorder_vec.emplace_back(root->val);
    } else {
      return false;
    }

    if (!traverse(root->right, inorder_vec)) {
      return false;
    }

    return true;
  }
};
// @lc code=end
