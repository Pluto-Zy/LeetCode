class Solution {
public:
  int maxProfit(vector<int>& prices) {
    // 若在第 i 天卖出，则必须在 [0, i) 天中的最低点买入股票
    int max_profit = 0;
    int min_price  = prices.front();
    for (int val : prices) {
      min_price  = std::min(min_price , val);
      max_profit = std::max(max_profit, val - min_price);
    }
    return max_profit;
  }
};