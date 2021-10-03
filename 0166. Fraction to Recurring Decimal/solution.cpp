class Solution {
public:
  string fractionToDecimal(int numerator, int denominator) {
    std::string result;
    // 判断符号
    if (numerator < 0 && denominator > 0 || numerator > 0 && denominator < 0)
      result += '-';
    // 转为正数计算
    // 此处考虑溢出问题，对于分子特别小分母特别大的用例，分子需要不断 * 10，直到比分母大为止。而分母可能是 int 的最大值，因此会溢出
    std::uint64_t _top    = numerator < 0   ? static_cast<std::uint64_t>(0 - static_cast<unsigned int>(numerator))   : numerator;
    std::uint64_t _bottom = denominator < 0 ? static_cast<std::uint64_t>(0 - static_cast<unsigned int>(denominator)) : denominator;
    // 计算整数部分
    result += std::to_string(_top / _bottom);
    _top = (_top % _bottom) * 10;
    if (!_top)
      return result;
    // 存在小数部分
    result += '.';
    std::unordered_map<unsigned int, int> _reminders;
    for (; _top; _top = (_top % _bottom) * 10) {
      if (auto iter = _reminders.find(_top); iter != _reminders.end()) {
        result.insert(result.begin() + iter->second, '(');
        result += ')';
        break;
      } else {
        _reminders.insert(iter, {_top, result.size()});
      }
      result += _top / _bottom + '0';
    }
    return result;
  }
};