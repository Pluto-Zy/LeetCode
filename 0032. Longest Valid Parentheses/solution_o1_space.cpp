class Solution {
  public:
    int longestValidParentheses(string s) {
      int result = 0;
      int left = 0, right = 0;
      for (auto iter = s.begin(); iter != s.end(); ++iter) {
        *iter == '(' ? ++left : ++right;
        if (left == right) {
          result = std::max(result, 2 * left);
        } else if (left < right) {
          left = right = 0;
        }
      }
      left = right = 0;
      for (auto iter = s.rbegin(); iter != s.rend(); ++iter) {
        *iter == ')' ? ++left : ++right;
        if (left == right) {
          result = std::max(result, 2 * left);
        } else if (left < right) {
          left = 0;
          right = 0;
        }
      }
      return result;
    }
};