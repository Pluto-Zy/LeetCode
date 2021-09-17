class Solution {
public:
    string addStrings(string num1, string num2) {
      std::string& short_str = (num1.size() < num2.size() ? num1 : num2);
      std::string& long_str  = (!(num1.size() < num2.size()) ? num1 : num2);
      bool flag = false;
      for (int i = 1; i <= short_str.size(); ++i) {
        char val = short_str[short_str.size() - i] + long_str[long_str.size() - i] + static_cast<int>(flag) - 2 * '0';
        flag = val >= 10;
        long_str[long_str.size() - i] = (flag ? val - 10 : val) + '0';
      }
      for (int i = long_str.size() - short_str.size() - 1; flag && i >= 0; --i) {
        if (long_str[i] == '9')
          long_str[i] = '0';
        else {
          ++long_str[i];
          flag = false;
        }
      }
      if (flag) {
        return '1' + long_str;
      }
      return long_str;
    }
};