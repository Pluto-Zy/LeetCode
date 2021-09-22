class Solution {
public:
  vector<int> grayCode(int n) {
    if (n == 0)
      return {0};
    std::vector<int> result;
    result.reserve(1 << n);
    _generate(result, n);
    return result;
  }

  void _generate(std::vector<int>& result, int n) {
    if (n == 1) {
      result.push_back(0);
      result.push_back(1);
      return;
    }
    _generate(result, --n);
    int size = result.size() - 1;
    for (int i = size; i >= 0; --i) {
      result.push_back(result[i] + (1 << n));
    }
  }
};