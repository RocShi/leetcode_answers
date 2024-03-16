/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第K小的元素
 *
 * https://leetcode.cn/problems/kth-smallest-element-in-a-bst/description/
 *
 * algorithms
 * Medium (76.69%)
 * Likes:    816
 * Dislikes: 0
 * Total Accepted:    320.6K
 * Total Submissions: 418K
 * Testcase Example:  '[3,1,4,null,2]\n1'
 *
 * 给定一个二叉搜索树的根节点 root ，和一个整数 k
 * ，请你设计一个算法查找其中第 k 个最小元素（从 1 开始计数）。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：root = [3,1,4,null,2], k = 1
 * 输出：1
 *
 *
 * 示例 2：
 *
 *
 * 输入：root = [5,3,6,2,4,null,null,1], k = 3
 * 输出：3
 *
 *
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中的节点数为 n 。
 * 1
 * 0
 *
 *
 *
 *
 * 进阶：如果二叉搜索树经常被修改（插入/删除操作）并且你需要频繁地查找第 k
 * 小的值，你将如何优化算法？
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
// 中序遍历，当遍历结果中达到 k 个元素时即可停止遍历
class Solution {
public:
  int kthSmallest(TreeNode *root, int k) {
    vector<int> inorder_vec;
    traverse(root, inorder_vec, k);
    return inorder_vec.back();
  }

  void traverse(TreeNode *root, vector<int> &inorder_vec, int k) {
    if (root == nullptr || inorder_vec.size() == k) {
      return;
    }

    traverse(root->left, inorder_vec, k);

    if (inorder_vec.size() < k) {
      inorder_vec.emplace_back(root->val);
    }

    traverse(root->right, inorder_vec, k);
  }
};
// @lc code=end
