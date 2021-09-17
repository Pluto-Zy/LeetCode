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
      if (!root)
        return {};
      std::vector<int> result;
      std::stack<TreeNode*> node_stack;
      node_stack.push(root);
      TreeNode* last_node = nullptr;
      while (!node_stack.empty()) {
        while (node_stack.top()->left)
          node_stack.push(node_stack.top()->left);

        while (!node_stack.empty()) {
          TreeNode* cur = node_stack.top();
          
          if (!cur->right || last_node == cur->right) {
            result.push_back(cur->val);
            node_stack.pop();
            last_node = cur;
          }
          else if(cur->right) {
            node_stack.push(cur->right);
            break;
          }
        }
      }
      return result;
    }
};
