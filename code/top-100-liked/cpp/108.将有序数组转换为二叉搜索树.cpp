/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
 *
 * https://leetcode.cn/problems/convert-sorted-array-to-binary-search-tree/description/
 *
 * algorithms
 * Easy (77.98%)
 * Likes:    1470
 * Dislikes: 0
 * Total Accepted:    427.2K
 * Total Submissions: 547.7K
 * Testcase Example:  '[-10,-3,0,5,9]'
 *
 * 给你一个整数数组 nums ，其中元素已经按 升序 排列，请你将其转换为一棵 高度平衡
 * 二叉搜索树。
 *
 * 高度平衡 二叉树是一棵满足「每个节点的左右两个子树的高度差的绝对值不超过 1
 * 」的二叉树。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [-10,-3,0,5,9]
 * 输出：[0,-3,9,-10,null,5]
 * 解释：[0,-10,5,null,-3,null,9] 也将被视为正确答案：
 *
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [1,3]
 * 输出：[3,1]
 * 解释：[1,null,3] 和 [3,1] 都是高度平衡二叉搜索树。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 10^4
 * -10^4 <= nums[i] <= 10^4
 * nums 按 严格递增 顺序排列
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
// 递归实现：从数组中间位置往两侧构造
class Solution {
public:
  TreeNode *sortedArrayToBST(vector<int> &nums) {
    return traverse(nums, 0, nums.size() - 1);
  }

  TreeNode *traverse(const vector<int> &nums, int left_idx, int right_idx) {
    TreeNode *root = nullptr;

    if (left_idx <= right_idx) {
      int mid_idx = left_idx + (right_idx - left_idx) / 2;
      root = new TreeNode(nums.at(mid_idx));
      root->left = traverse(nums, left_idx, mid_idx - 1);
      root->right = traverse(nums, mid_idx + 1, right_idx);
    }

    return root;
  }
};
// @lc code=end
