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
    vector<int> inorderTraversal(TreeNode* root) {
      if (!root)
        return {};
      std::vector<int> result;
      _inorder(result, root);
      return result;
    }

    // `root` cannot be empty this time.
    void _inorder(std::vector<int>& result, TreeNode* root) {
      if (root->left)
        _inorder(result, root->left);
      result.push_back(root->val);
      if (root->right)
        _inorder(result, root->right);
    }
};