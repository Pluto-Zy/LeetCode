class Solution {
public:
  int maxScoreSightseeingPair(vector<int>& values) {
    int _result = 0;
    int _max_val = values[0]/* + 0 */; // 统计当前的 values[j] 前的 values 的最大值
    for (int i = 1; i < values.size(); ++i) {
      _result = std::max(_result, _max_val + values[i] - i);
      _max_val = std::max(_max_val, values[i] + i);
    }
    return _result;
  }
};