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
    bool isValidBST(TreeNode* root) {
      if (!root)
        return true;
      std::stack<TreeNode*> node_stack;
      while (root) {
        node_stack.push(root);
        root = root->left;
      }
      root = node_stack.top();
      int last_val = root->val;
      root = root->right;
      node_stack.pop();
      while (!node_stack.empty() || root) {
        while (root) {
          node_stack.push(root);
          root = root->left;
        }
        root = node_stack.top();
        node_stack.pop();
        if (root->val <= last_val)
          return false;
        last_val = root->val;
        root = root->right;
      }
      return true;
    }
};