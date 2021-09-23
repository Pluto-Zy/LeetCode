class Solution {
private:
  // 寻找 int 范围内的 3 的最大约数
  static constexpr int _biggest() {
    int result = 3;
    while (std::numeric_limits<int>::max() / 3 >= result)
      result *= 3;
    return result;
  }
public:
  bool isPowerOfThree(int n) {
    constexpr int max_val = _biggest();
    return n > 0 && max_val % n == 0;
  }
};