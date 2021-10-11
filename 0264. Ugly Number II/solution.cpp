class Solution {
public:
  int nthUglyNumber(int n) {
    // 从已经生成的丑数中 *2 *3 *5 得到后续丑数
    // 每个丑数都应乘 3 次
    // 重点是对结果排序
    // 使用 3 个指针，分别指向 3 种乘法当前工作到的整数
    std::vector<int> dp(n);
    dp[0] = 1;
    auto _ptr_2 = 0, _ptr_3 = _ptr_2, _ptr_5 = _ptr_2;
    for (int i = 1; i < n; ++i) {
      int _temp_2 = dp[_ptr_2] * 2, _temp_3 = dp[_ptr_3] * 3, _temp_5 = dp[_ptr_5] * 5;
      dp[i] = std::min<int>({_temp_2, _temp_3, _temp_5});
      if (dp[i] == _temp_2)
        ++_ptr_2;
      // cannot use `else if` here !!!
      if (dp[i] == _temp_3)
        ++_ptr_3;
      if (dp[i] == _temp_5)
        ++_ptr_5;
    }
    return dp[n - 1];
  }
};