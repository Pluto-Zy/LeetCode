class Solution {
public:
  string longestPalindrome(string s) {
    int max_begin = 0, max_size = 0;
    for (int i = 0; i < s.size(); ++i) {
      auto result1 = expandCenter(s, i, i);
      auto result2 = expandCenter(s, i, i + 1);
      if (std::get<1>(result1)> max_size) {
        max_begin = std::get<0>(result1);
        max_size = std::get<1>(result1);
      }
      if (std::get<1>(result2) > max_size) {
        max_begin = std::get<0>(result2);
        max_size = std::get<1>(result2);
      }
    }
    return s.substr(max_begin, max_size);
  }

  std::tuple<int, int> expandCenter(const std::string& s, int left, int right) {
    for (; left >= 0 && right < s.size() && s[left] == s[right]; --left, ++right)
      ;
    return { left + 1, right - left - 1 };
  }
};