class Solution {
public:
  vector<int> partitionLabels(string s) {
    // 统计每个字母的最后出现位置
    // 然后正向遍历，计算从当前字符开始到达的最远位置
    int last_index[26]{};
    for (int i = s.size() - 1; i >= 0; --i) {
      last_index[s[i] - 'a'] = std::max(last_index[s[i] - 'a'], i);
    }
    std::vector<int> result;
    int start_pos = 0;
    int end_pos = last_index[s[0] - 'a'];
    for (int i = 0; i < s.size(); ++i) {
      end_pos = std::max(end_pos, last_index[s[i] - 'a']);
      if (i == end_pos) {
        result.push_back(end_pos - start_pos + 1);
        start_pos = end_pos + 1;
      }
    }
    return result;
  }
};