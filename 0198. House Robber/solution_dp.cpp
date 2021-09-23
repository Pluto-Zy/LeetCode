class Solution {
public:
  int rob(vector<int>& nums) {
    // dp[i]: 偷窃第 i 家的最高金额
    // dp[i] = max(dp[i - 2] + nums[i], dp[i - 1])
    // dp[0] = nums[0], dp[1] = nums[1]
    if (nums.size() == 1)
      return nums[0];
    if (nums.size() == 2)
      return std::max(nums[0], nums[1]);
    int dp_last_2 = nums[0], dp_last_1 = std::max(nums[0], nums[1]);
    for (int i = 2; i < nums.size(); ++i) {
      int temp = std::max(dp_last_2 + nums[i], dp_last_1);
      dp_last_2 = dp_last_1;
      dp_last_1 = temp;
    }
    return dp_last_1;
  }
};