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
    vector<vector<int>> levelOrder(TreeNode* root) {
      if (!root)
        return {};
      std::vector<std::vector<int>> result;
      std::queue<TreeNode*> node_queue;
      node_queue.push(root);
      while (!node_queue.empty()) {
        std::size_t count = node_queue.size();
        std::vector<int> temp;
        while (count--) {
          TreeNode* cur = node_queue.front();
          node_queue.pop();
          temp.push_back(cur->val);
          if (cur->left)
            node_queue.push(cur->left);
          if (cur->right)
            node_queue.push(cur->right);
        }
        result.emplace_back(std::move(temp));
      }
      return result;
    }
};