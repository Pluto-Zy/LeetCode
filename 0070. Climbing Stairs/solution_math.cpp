class Solution {
public:
  int climbStairs(int n) {
    int result = 0;
    for (int i = 0; i < n; ++i) {
      result += c(i, n - i);
    }
    return result;
  }
private:
  static int c(int n1, int n2) {
    if (n1 == 0)
      return 1;
    long long result = 1;
    for (int i = n2 - n1 + 1, j = 1; j <= n1; ++j, ++i) {
      result = result * i / j;
    }
    return result;
  }
};