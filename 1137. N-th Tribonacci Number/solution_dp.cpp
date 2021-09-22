class Solution {
public:
  int tribonacci(int n) {
    if (n == 0)
      return 0;
    if (n == 1 || n == 2)
      return 1;
    int last_1 = 0, last_2 = 1, last_3 = 1;
    --n;
    while (--n) {
      int result = last_1 + last_2 + last_3;
      last_1 = last_2;
      last_2 = last_3;
      last_3 = result;
    }
    return last_3;
  }
};