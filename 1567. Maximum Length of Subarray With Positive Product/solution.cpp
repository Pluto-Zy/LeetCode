class Solution {
public:
  int getMaxLen(vector<int>& nums) {
    int _result         = 0;
    int _min_pos        = nums.size();
    int _max_pos        = 0;
    int _start          = 0;
    int _negative_count = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] < 0) {
        _min_pos = std::min(_min_pos, i);
        _max_pos = std::max(_max_pos, i);
        ++_negative_count;
      } else if (nums[i] == 0) {
        if (_negative_count % 2 == 0) {
          _result = std::max(_result, i - _start);
        } else {
          _result = std::max({_result, _min_pos - _start, _max_pos - _start, i - _min_pos - 1});
        }
        _negative_count = 0;
        _start = i + 1;
        _min_pos = nums.size();
        _max_pos = _start;
      }
    }
    if (_negative_count % 2 == 0) {
      _result = std::max(_result, static_cast<int>(nums.size() - _start));
    } else {
      _result = std::max({_result, _min_pos - _start, _max_pos - _start, static_cast<int>(nums.size() - _min_pos - 1)});
    }
    return _result;
  }
};