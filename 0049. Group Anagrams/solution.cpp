class Solution {
  std::size_t prime[26] = {
    2, 3, 5, 7, 11, 
    13, 17, 19, 23, 29, 
    31, 37, 41, 43, 47, 
    53, 59, 61, 67, 71,
    73, 79, 83, 89, 97, 101
  };

public:
  // 好的思路，但对于本题不一定完全正确（算法有漏洞）
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    std::unordered_map<std::size_t, std::vector<std::string>> dict;
    for (std::string& s : strs) {
      auto& vec = dict[hash_str(s)];
      vec.emplace_back(std::move(s));   // not good!
    }
    std::vector<std::vector<std::string>> result;
    for (auto iter = dict.begin(); iter != dict.end(); ++iter) {
      result.emplace_back(std::move(iter->second));
    }
    return result;
  }

  // 将字符串映射到整数：字母异位词的映射值相同
  // 26 个字母对应 26 个素数，使用乘法得到结果
  std::size_t hash_str(const std::string& s) {
    std::size_t result = 1;
    for (char ch : s) {
      result *= prime[ch - 'a'];
      result %= 1000000007;   // 防止溢出，但有潜在的哈希冲突，因此算法不一定完全正确
    }
    return result;
  }
};