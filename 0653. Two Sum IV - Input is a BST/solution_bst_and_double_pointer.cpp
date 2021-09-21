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
  bool findTarget(TreeNode* root, int k) {
    std::vector<int> nums = _in_order(root);
    for (int left = 0, right = nums.size() - 1; left != right;) {
      int sum = nums[left] + nums[right];
      if (sum < k)
        ++left;
      else if (sum > k)
        --right;
      else
        return true;
    }
    return false;
  }

  std::vector<int> _in_order(TreeNode* root) {
    std::vector<int> result;
    std::stack<TreeNode*> node_stack;
    while (root || !node_stack.empty()) {
      while (root) {
        node_stack.push(root);
        root = root->left;
      }
      root = node_stack.top();
      node_stack.pop();
      result.push_back(root->val);
      root = root->right;
    }
    return result;
  }
};