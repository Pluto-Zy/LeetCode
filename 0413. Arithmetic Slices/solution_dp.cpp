class Solution {
public:
  int numberOfArithmeticSlices(vector<int>& nums) {
    // dp[i]: 以 nums[i] 结尾的等差数列个数
    // dp[0] = dp[1] = 0
    // dp[i] = dp[i - 1] + 1, if nums[i], nums[i - 1], nums[i - 2] 为等差数列
    // dp[i] = 0, 其它
    // 以 nums[i] 结尾的等差数列，必然满足后三项（i, i-1, i-2）是等差数列
    // 在后三项结尾的基础上，向前延展任意多的等差项即可。
    // 若向前延展 0 项，则得到（i-2, i-1, i）组成的等差数列；
    // 若向前延展非 0 项，则为 nums[i - 1] 结尾的等差数列数量，即 dp[i - 1]
    int dp = 0;
    int result = 0;
    for (int i = 2; i < nums.size(); ++i) {
      if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) {
        ++dp;
        result += dp;
      } else {
        dp = 0;
      }
    }
    return result;
  }
};