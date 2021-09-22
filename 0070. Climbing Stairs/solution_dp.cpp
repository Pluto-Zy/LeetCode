class Solution {
public:
  int climbStairs(int n) {
    // dp[i]: 爬到第 i 级台阶的方法数量
    // dp[i] = dp[i - 1] + dp[i - 2]  ->  斐波那契数列
    // dp[1] = 1, dp[2] = 2
    int last_1 = 1, last_2 = 1;
    while (--n) {
      int result = last_1 + last_2;
      last_1 = last_2;
      last_2 = result;
    }
    return last_2;
  }
};