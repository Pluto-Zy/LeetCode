class Solution {
  public:
    int longestValidParentheses(string s) {
      std::vector<int> dp(s.size(), 0);
      int result = 0;
      for (int i = 1; i < s.size(); ++i) {
        if (s[i] == '(')
          continue;
        if (s[i - 1] == '(') {  // condition: xxxx()
          dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
        } else {                // condition: xxxx))
          int idx = i - dp[i - 1] - 1;
          if (idx >= 0 && s[idx] == '(') {
            dp[i] = dp[i - 1] + 2 + (idx - 1 < 0 ? 0 : dp[idx - 1]);
          }
        }
        result = std::max(result, dp[i]);
      }
      return result;
    }
};