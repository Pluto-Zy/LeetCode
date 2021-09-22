class Solution {
public:
  int fib(int n) {
    if (n == 0)
      return 0;
    if (n == 1)
      return 1;
    int last_1 = 0, last_2 = 1, result = 0;
    while (--n) {
      result = last_1 + last_2;
      last_1 = last_2;
      last_2 = result;
    }
    return result;
  }
};