class Solution {
public:
  bool wordBreak(string s, vector<string>& wordDict) {
    // dp[i]: 前 i 个字符组成的字符串能否满足要求
    // dp[i] = true, 如果存在 j，使得 dp[j] == true 且 s[j .. i] 存在于 wordDict
    
    // 统计 wordDict 中最大和最小长度的字符
    // 这一步也可以和插入到 unordered_map 结合
    std::unordered_set<std::string> dict/*(wordDict.begin(), wordDict.end())*/;
    int max_length = wordDict[0].size(), min_length = wordDict[0].size();
    for (std::string& str : wordDict) {
      max_length = std::max(max_length, static_cast<int>(str.size()));
      min_length = std::min(min_length, static_cast<int>(str.size()));
      dict.insert(std::move(str));  // std::move: 此处为不好的做法
    }

    std::unique_ptr<bool[]> dp(new bool[s.size() + 1]{true});  // dp[0] = true
    for (int i = min_length; i <= s.size(); ++i) {
      for (int j = min_length; j <= max_length && j <= i; ++j) {
        if (dp[i - j] && dict.find(s.substr(i - j, j)) != dict.end()) {
          dp[i] = true;
          break;
        }
      }
    }
    return dp[s.size()];
  }
};