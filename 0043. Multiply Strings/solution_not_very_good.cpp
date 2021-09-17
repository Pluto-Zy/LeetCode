class Solution {
public:
    string multiply(string num1, string num2) {
      // 一位数与被乘数的乘积
      std::unordered_map<char, std::string> sub_result;
      std::string& short_str = (num1.size() < num2.size() ? num1 : num2);
      std::string& long_str  = (!(num1.size() < num2.size()) ? num1 : num2);
      std::string result;
      for (int i = short_str.size() - 1; i >= 0; --i) {
        if (sub_result.find(short_str[i]) == sub_result.end()) {
          sub_result.insert({short_str[i], multiple_char_str(long_str, short_str[i])});
        }
        result = addStrings(result, sub_result[short_str[i]] + std::string(short_str.size() - i - 1, '0'));
      }
      for (int i = 0; i < result.size() - 1; ++i) {
        if (result[i] != '0')
          return result.substr(i);
      }
      return result.substr(result.size() - 1);
    }

    std::string multiple_char_str(const std::string& num, char ch) {
      std::int8_t next = 0;
      ch -= '0';
      std::string result(num.size() + 1, '0');
      for (int i = num.size() - 1; i >= 0; --i) {
        std::int8_t val = ch * (num[i] - '0') + next;
        next = val / 10;
        val -= next * 10;
        result[i + 1] = val + '0';
      }
      result[0] = next + '0';
      return result;
    }

    string addStrings(const string& num1, const string& num2) {
      const std::string& short_str = (num1.size() < num2.size() ? num1 : num2);
      const std::string& long_str  = (!(num1.size() < num2.size()) ? num1 : num2);
      if (short_str.empty())
        return long_str;
      std::string result(long_str.size(), '0');
      bool flag = false;
      for (int i = 1; i <= short_str.size(); ++i) {
        char val = short_str[short_str.size() - i] + long_str[long_str.size() - i] + static_cast<int>(flag) - 2 * '0';
        flag = val >= 10;
        result[result.size() - i] = (flag ? val - 10 : val) + '0';
      }
      for (int i = long_str.size() - short_str.size() - 1; i >= 0; --i) {
        if (long_str[i] == '9' && flag)
          result[i] = '0';
        else {
          result[i] = long_str[i] + static_cast<int>(flag);
          flag = false;
        }
      }
      if (flag) {
        return '1' + result;
      }
      return result;
    }
};