class Solution {
public:
  vector<string> findRepeatedDnaSequences(string s) {
    // 4 种字符：用 2bit 表示每个字符
    // 00: A; 01: C; 10: G; 11: T
    // 一个长度为 10 的字符串，对应 20bit，用 32bit 整数保存

    // 滑动窗口：每次加入一个字符，移除一个字符，无需计算所有的 10 个字符
    // 先计算最初的 10 个字符的整数值
    if (s.size() < 10)
      return {};
    // 低位字符位于整数高位
    std::uint32_t cur_val = 0;
    for (int i = 0; i < 10; ++i) {
      cur_val <<= 2;
      if (s[i] > 'D')
        cur_val |= 2;
      if (s[i] == 'C' || s[i] == 'T')
        cur_val |= 1;
    }
    // 建立哈希表并滑动遍历
    std::unordered_map<std::uint32_t, int> str_map {{cur_val, 1}};
    for (int i = 10; i < s.size(); ++i) {
      // s[i] 是当前划入的元素
      cur_val <<= 2;
      if (s[i] > 'D')
        cur_val |= 2;
      if (s[i] == 'C' || s[i] == 'T')
        cur_val |= 1;
      // 移除高位
      cur_val &= (1 << 20) - 1;
      ++str_map[cur_val];
    }
    // 整数转字符串
    std::vector<std::string> result;
    for (auto iter = str_map.begin(); iter != str_map.end(); ++iter) {
      if (iter->second != 1) {
        result.emplace_back(num_to_str(iter->first));
      }
    }
    return result;
  }

  std::string num_to_str(std::uint32_t val) {
    static char map[] = {'A', 'C', 'G', 'T'};
    std::string result(10, '\0');
    for (int i = 9; i >= 0; --i, val >>= 2) {
      result[i] = map[val & 3]; // binary: 11
    }
    return result;
  }
};