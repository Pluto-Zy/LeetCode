class Solution {
public:
  string toHex(int num) {
    if (num == 0)
      return "0";
    std::string _result(8, '0');
    std::size_t idx = 7;
    for (unsigned int _src = static_cast<unsigned int>(num); _src; _src >>= 4, --idx) {
      unsigned int _val = _src & 0xF;
      if (_val < 10)
        _result[idx] = '0' + _val;
      else
        _result[idx] = 'a' + (_val - 10);
    }
    return _result.substr(idx + 1);
  }
};