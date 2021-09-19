class Solution {
  public:
    double myPow(double x, int n) {
      unsigned int _n = (n > 0 ? n : -static_cast<std::int64_t>(n));
      double result = 1;
      for (double _temp = x; _n; _n >>= 1, _temp *= _temp) {
        if (_n & 1)
          result *= _temp;
      }
      return n < 0 ? 1 / result : result;
    }
};