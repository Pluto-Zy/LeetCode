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
    int maxDepth(TreeNode* root) {
      if (!root)
        return 0;
      int result = 0;
      std::queue<TreeNode*> node_queue;
      node_queue.push(root);
      while (!node_queue.empty()) {
        std::size_t count = node_queue.size();
        ++result;
        while (count--) {
          TreeNode* cur = node_queue.front();
          node_queue.pop();
          if (cur->left)
            node_queue.push(cur->left);
          if (cur->right)
            node_queue.push(cur->right);
        }
      }
      return result;
    }
};