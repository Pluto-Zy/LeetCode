class Solution {
public:
  int getSum(int a, int b) {
    int result = 0;
    unsigned carry = 0;
    unsigned _mask = 1;
    for (unsigned i = 0; i < sizeof(int) * 8; ++i) {
      result |= binary_add(a & _mask, b & _mask, carry);
      carry <<= 1;
      _mask <<= 1;
    }
    return result;
  }

  static unsigned binary_add(unsigned n1, unsigned n2, unsigned& carry) {
    // n1  n2  carry  result  next_carry
    // 0   0     0      0          0
    // 0   0     1      1          0
    // 0   1     0      1          0
    // 0   1     1      0          1
    // 1   0     0      1          0
    // 1   0     1      0          1
    // 1   1     0      0          1
    // 1   1     1      1          1

    // result = n1 ^ n2 ^ carry
    // next_carry = ((n1 ^ n2) & carry) | (n1 & n2)
    unsigned result = n1 ^ n2 ^ carry;
    carry = ((n1 ^ n2) & carry) | (n1 & n2);
    return result;
  }
};