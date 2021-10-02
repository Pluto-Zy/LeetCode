class Solution {
public:
  int maxProfit(vector<int>& prices) {
    // 找到所有的上坡区间
    int _result = 0;
    for (int i = 1; i < prices.size(); ++i) {
      _result += std::max(prices[i] - prices[i - 1], 0);
      /*
      * 等价于：
      * if (prices[i] > prices[i - 1]) {
      *   _result += prices[i] - prices[i - 1]; 
      * }
      */
    }
    return _result;
  }
};