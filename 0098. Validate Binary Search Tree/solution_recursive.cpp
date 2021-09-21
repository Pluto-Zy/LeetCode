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
      return _check(root, std::numeric_limits<long long>::max(), std::numeric_limits<long long>::min());
    }

    bool _check(TreeNode* root, long long high, long long low) {
      if (!root)
        return true;
      if (root->val >= high || root->val <= low)
        return false;
      return _check(root->left, root->val, low) && _check(root->right, high, root->val);
    }
};