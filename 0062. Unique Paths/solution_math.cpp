class Solution {
public:
    int uniquePaths(int m, int n) {
      // C(a, m + n - 2), where a = min(m - 1, n - 1)
      return _c(std::min(m - 1, n - 1), m + n - 2);
    }

    static int _c(int num1, int num2) {
      std::uint64_t result = 1;
      for (int i = 1, j = num2 - num1 + 1; i <= num1; ++i, ++j) {
        result = result * j / i;
      }
      return result;
    }
};