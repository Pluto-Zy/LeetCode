class Solution {
public:
  int maxProfit(vector<int>& prices, int fee) {
    /*
    * dp[i]: 第 i 天结束后，当前的最大收益
    * dp[i][0]: 第 i 天**结束**后手中持有一支股票
    * dp[i][1]: 第 i 天**结束**后手中没有股票
    * 
    * dp[i][0]:
    *     当天买入股票，或之前已经买入
    * dp[i][0] = max(dp[i - 1][1] - prices[i], dp[i - 1][0])
    * 
    * dp[i][1]:
    *     当天卖出股票，或之前已经卖出
    * dp[i][1] = max(dp[i - 1][0] + prices[i] - fee, dp[i - 1][1])
    * 
    * 边界：
    * dp[0][0] = -prices[0]
    * dp[0][1] = 0
    * 
    * 使用滚动数组优化空间
    */

    int _dp_0 = -prices[0];
    int _dp_1 = 0;
    for (int i = 1; i < prices.size(); ++i) {
      int _temp_0 = std::max(_dp_1 - prices[i], _dp_0);
      _dp_1 = std::max(_dp_0 + prices[i] - fee, _dp_1);
      _dp_0 = _temp_0;
    }
    return _dp_1;
  }
};