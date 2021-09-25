class Solution {
public:
  int minDistance(string word1, string word2) {
    // 本质是寻找 word1 和 word2 的公共最长子序列长度
    if (word1.size() > word2.size())
      std::swap(word1, word2);
    // word1 是较短的字符串
    std::vector<std::vector<int>> dp(2, std::vector<int>(word1.size() + 1));
    for (int i = 0; i < word2.size(); ++i) {
      char ch = word2[i];
      for (int j = 0; j < word1.size(); ++j) {
        if (ch == word1[j])
          dp[1][j + 1] = dp[0][j] + 1;
        else
          dp[1][j + 1] = std::max(dp[1][j], dp[0][j + 1]);
      }
      std::swap(dp[0], dp[1]);
    }
    return word1.size() + word2.size() - 2 * dp[0][word1.size()];
  }
};