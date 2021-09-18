/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
      return _is_symmetric_tree(root, root);
    }

    bool _is_symmetric_tree(TreeNode* left, TreeNode* right) {
      if (!left && !right)
        return true;
      if (left == right && left)
        return _is_symmetric_tree(left->left, left->right);
      if (left && right)
        return left->val == right->val && _is_symmetric_tree(left->left, right->right) && _is_symmetric_tree(left->right, right->left);
      return false;
    }
};