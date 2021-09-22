class Solution {
public:
  vector<int> grayCode(int n) {
    if (n == 0)
      return {0};
    std::vector<int> result {0, 1};
    result.reserve(1 << n);
    for (int i = 1; i < n; ++i) {
      int size = result.size() - 1;
      for (int j = size; j >= 0; --j) {
        result.push_back(result[j] + (1 << i));
      }
    }
    return result;
  }
};