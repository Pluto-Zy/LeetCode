class Solution {
  public:
    double myPow(double x, int n) {
      unsigned int _n = (n > 0 ? n : -static_cast<std::int64_t>(n));
      double result = _pow(x, _n);
      return n < 0 ? 1 / result : result;
    }

    double _pow(double x, unsigned int n) {
      if (n == 0)
        return 1;
      if (n == 1)
        return x;
      double _half = _pow(x, n >> 1);
      if (n & 1)
        return _half * _half * x;
      return _half * _half;
    }
};