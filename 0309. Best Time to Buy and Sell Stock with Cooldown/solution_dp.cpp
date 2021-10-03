class Solution {
public:
  int maxProfit(vector<int>& prices) {
    /*
    * dp[i]: 第 i 天结束后，当前的最大收益
    * dp[i][0]: 第 i 天**结束**后手中持有一支股票
    * dp[i][1]: 第 i 天**结束**后手中没有股票，且不处于冷冻期
    * dp[i][2]: 第 i 天**结束**后手中没有股票，且处于冷冻期
    * 
    * dp[i][0]:
    *    1. 第 i 天当天买入了一支股票，那么前一天**结束**后，
    *       不能处于冷冻期，即 dp[i - 1][1] - prices[i]
    *    2. 第 i 天没有购买股票，则与前一天的收益相同，即 dp[i - 1][0]
    * 因此，dp[i][0] = max(dp[i - 1][1] - prices[i], dp[i - 1][0])
    * 
    * dp[i][1]:
    *    1. 当天结束后不处于冷冻期，说明当天没有卖出股票，也没有买入股票，
    *       即 dp[i - 1][1] 和 dp[i - 1][2] 的最大值
    * 因此，dp[i][1] = max(dp[i - 1][1], dp[i - 1][2])
    * 
    * dp[i][2]:
    *    1. 当天结束后处于冷冻期，说明当天卖出了股票
    * 因此，dp[i][2] = dp[i - 1][0] + prices[i]
    * 
    * 边界：
    * dp[0][0] = -prices[0]
    * dp[0][1] = dp[0][2] = 0
    * 
    * 使用滚动数组优化空间
    */

    int _dp_0 = -prices[0];
    int _dp_1 = 0;
    int _dp_2 = 0;
    for (int i = 1; i < prices.size(); ++i) {
      int _temp_0 = std::max(_dp_1 - prices[i], _dp_0);
      _dp_1 = std::max(_dp_1, _dp_2);
      _dp_2 = _dp_0 + prices[i];
      _dp_0 = _temp_0;
    }
    return std::max(_dp_1, _dp_2);
  }
};