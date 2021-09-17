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
      std::stack<TreeNode*> stack;
      TreeNode* cur = root;
      while (cur) {
        result.push_back(cur->val);
        if (cur->right)
          stack.push(cur->right);
        if (cur->left)
          stack.push(cur->left);
        if (stack.empty()) {
          break;
        }
        cur = stack.top();
        stack.pop();
      }
      return result;
    }
};