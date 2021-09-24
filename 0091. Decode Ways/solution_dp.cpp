class Solution {
public:
  int numDecodings(string s) {
    // dp[i]: 以 s[i] 结尾的字符串有几种映射方法
    // dp[i] += dp[i - 1], if 1 <= s[i] <= 9
    // dp[i] += dp[i - 2], if s[i - 1] == 1 or (s[i - 1] == 2 and 0 <= s[i] <= 6)
    // dp[0] = 1
    if (s[0] == '0')
      return 0;
    int _first = 1, _second = 1;
    for (int i = 1; i < s.size(); ++i) {
      int result = 0;
      if (s[i] != '0')
        result += _second;
      if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6'))
        result += _first;
      _first = _second;
      _second = result;
    }
    return _second;
  }
};