class Solution {
public:
  bool wordPattern(string pattern, string s) {
    std::istringstream sin(s);
    std::string _map[26];
    std::unordered_set<std::string> _dict;
    int _idx = 0;
    for (std::string _cur_str; sin >> _cur_str && _idx < pattern.size(); ++_idx) {
      int _temp = pattern[_idx] - 'a';
      if (_map[_temp].empty()) {
        _map[_temp] = _cur_str;
        if (auto iter = _dict.find(_cur_str); iter != _dict.end()) {
          return false;
        } else {
          _dict.insert(iter, _cur_str);
        }
      }
      else if (_map[_temp] != _cur_str)
        return false;
    }
    return _idx == pattern.size() && !sin;
  }
};