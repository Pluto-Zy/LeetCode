class Solution {
public:
  vector<string> findRepeatedDnaSequences(string s) {
    std::unordered_map<std::string, int> str_map;
    for (int i = 0; i < static_cast<int>(s.size()) - 9; ++i) {
      ++str_map[s.substr(i, 10)];
    }
    std::vector<std::string> result;
    for (auto iter = str_map.begin(); iter != str_map.end(); ++iter) {
      if (iter->second != 1)
        result.emplace_back(std::move(iter->first));
    }
    return result;
  }
};