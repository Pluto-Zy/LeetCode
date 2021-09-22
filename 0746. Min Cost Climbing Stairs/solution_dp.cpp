class Solution {
public:
  int minCostClimbingStairs(vector<int>& cost) {
    // dp[i]: 爬到第 i 级阶梯的最小体力消耗
    // dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2])
    // dp[0] = 0, dp[1] = 0
    int dp_0 = 0, dp_1 = 0;
    for (int i = 1; i < cost.size(); ++i) {
      int dp_temp = std::min(dp_1 + cost[i], dp_0 + cost[i - 1]);
      dp_0 = dp_1;
      dp_1 = dp_temp;
    }
    return dp_1;
  }
};