class Solution {
public:
  int maxProfit(vector<int>& prices) {
    // 若在第 i 天卖出，则必须在 [0, i) 天中的最低价格买入
    // 在所有峰值时卖出股票，在峰值前的最小值买入。峰值过后，重新计算最小值
    int _min_price  = prices.front();
    int _max_profit = 0;
    for (int i = 1; i < prices.size() - 1; ++i) {
      _min_price = std::min(_min_price, prices[i]);
      if (prices[i] > prices[i + 1]) {
        _max_profit += prices[i] - _min_price;
        _min_price = prices[i];
      }
    }
    _min_price = std::min(_min_price, prices.back());
    _max_profit += prices.back() - _min_price;
    return _max_profit;
  }
};