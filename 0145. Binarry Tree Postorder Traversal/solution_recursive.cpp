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
    vector<int> postorderTraversal(TreeNode* root) {
      std::vector<int> result;
      _postorder(result, root);
      return result;
    }

    void _postorder(std::vector<int>& result, TreeNode* root) {
      if (!root)
        return;
      _postorder(result, root->left);
      _postorder(result, root->right);
      result.push_back(root->val);
    }
};