/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
 *
 * https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (71.21%)
 * Likes:    2199
 * Dislikes: 0
 * Total Accepted:    578K
 * Total Submissions: 811.7K
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * 给定两个整数数组 preorder 和 inorder ，其中 preorder 是二叉树的先序遍历，
 * inorder 是同一棵树的中序遍历，请构造二叉树并返回其根节点。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
 * 输出: [3,9,20,null,null,15,7]
 *
 *
 * 示例 2:
 *
 *
 * 输入: preorder = [-1], inorder = [-1]
 * 输出: [-1]
 *
 *
 *
 *
 * 提示:
 *
 *
 * 1 <= preorder.length <= 3000
 * inorder.length == preorder.length
 * -3000 <= preorder[i], inorder[i] <= 3000
 * preorder 和 inorder 均 无重复 元素
 * inorder 均出现在 preorder
 * preorder 保证 为二叉树的前序遍历序列
 * inorder 保证 为二叉树的中序遍历序列
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
class Solution {
public:
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    return build(preorder, 0, preorder.size(), inorder, 0, inorder.size());
  }

  TreeNode *build(const vector<int> &preorder, size_t pre_start, size_t pre_end,
                  const vector<int> &inorder, size_t in_start, size_t in_end) {
    TreeNode *root = nullptr;
    if (pre_start < pre_end) {
      auto root_val = preorder.at(pre_start);
      size_t root_in_idx = 0;
      for (size_t i = in_start; i < in_end; ++i) {
        if (inorder.at(i) == root_val) {
          root_in_idx = i;
          break;
        }
      }

      root = new TreeNode(root_val);
      root->left =
          build(preorder, pre_start + 1, pre_start + 1 + root_in_idx - in_start,
                inorder, in_start, root_in_idx);
      root->right = build(preorder, pre_start + 1 + root_in_idx - in_start,
                          pre_end, inorder, root_in_idx + 1, in_end);
    }
    return root;
  }
};
// @lc code=end
