class Solution {
public:
  int longestPalindrome(string s) {
    std::sort(s.begin(), s.end());
    int result = 0;
    int _sub_length = 1;
    bool _has_odd = false;
    for (int i = 1; i < s.size(); ++i, ++_sub_length) {
      if (s[i] != s[i - 1]) {
        result += _sub_length;
        if (_sub_length & 1) {
          --result;
          _has_odd = true;
        }
        _sub_length = 0;
      }
    }
    result += _sub_length;
    if (_sub_length & 1) {
      --result;
      _has_odd = true;
    }
    return _has_odd ? ++result : result;
  }
};