class Solution {
public:
  int longestCommonSubsequence(string text1, string text2) {
    // dp[i][j]: s1[0, i) 和 s2[0, j) 的最长公共子序列长度
    // dp[i][j] = 0, if i == 0 or j == 0
    // dp[i][j] = 
    //     dp[i - 1][j - 1] + 1, if s1[i - 1] == s2[j - 1]
    //     max(dp[i - 1][j], dp[i][j - 1]), if s1[i - 1] != s2[j - 1]
    // 公共子序列：允许不连续
    // 滚动数组：极大优化空间消耗
    std::vector<std::vector<int>> dp(2, std::vector<int>(text2.size() + 1));
    for (int i = 1; i <= text1.size(); ++i) {
      char ch = text1[i - 1];
      for (int j = 1; j <= text2.size(); ++j) {
        if (ch == text2[j - 1])
          dp[1][j] = dp[0][j - 1] + 1;
        else
          dp[1][j] = std::max(dp[0][j], dp[1][j - 1]);
      }
      std::swap(dp[0], dp[1]);
    }
    return dp[0][text2.size()];
  }
};