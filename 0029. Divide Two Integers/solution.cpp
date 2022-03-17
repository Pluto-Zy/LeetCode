class Solution {
public:
    int divide(int dividend, int divisor) {
      if (divisor == 1)
        return dividend;
      if (divisor == -1) {
        if (dividend == std::numeric_limits<int>::min())
          return std::numeric_limits<int>::max();
        return -dividend;
      }
      bool negative = (dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0);
      dividend = (dividend > 0 ? -dividend : dividend); // 被除数为负数
      divisor = (divisor > 0 ? -divisor : divisor);     // 除数为负数
      return negative ? 0 - expand(dividend, divisor) : expand(dividend, divisor);
    }
    int expand(int dividend, int divisor) {
      if (dividend > divisor)
        return 0;
      int result = 1;
      int temp = divisor;
      for (; dividend - divisor <= divisor; divisor += divisor, result <<= 1)
        ;
      return result + expand(dividend - divisor, temp); 
    }
};