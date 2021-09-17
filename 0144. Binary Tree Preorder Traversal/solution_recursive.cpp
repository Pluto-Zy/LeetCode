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
    vector<int> preorderTraversal(TreeNode* root) {
      std::vector<int> result;
      _preorder(result, root);
      return result;
    }

    void _preorder(std::vector<int>& result, TreeNode* root) {
      if (!root)
        return;
      // root -> left -> right
      result.push_back(root->val);
      _preorder(result, root->left);
      _preorder(result, root->right);
    }
};
