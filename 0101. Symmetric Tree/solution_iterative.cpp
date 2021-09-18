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
      std::queue<TreeNode*> node_queue;
      node_queue.push(root);
      node_queue.push(root);
      while (!node_queue.empty()) {
        TreeNode* left  = node_queue.front();
        node_queue.pop();
        TreeNode* right = node_queue.front();
        node_queue.pop();
        if ((!left && right) || (left && !right) || (left && right && left->val != right->val))
          return false;
        if (left && right) {
          node_queue.push(left->right);
          node_queue.push(right->left);
          node_queue.push(left->left);
          node_queue.push(right->right);
        }
      }
      return true;
    }
};