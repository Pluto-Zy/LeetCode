class Solution {
public:
  int maxSubArray(vector<int>& nums) {
    // dp[i]: 以 nums[i] **结尾**的最大子序和
    // dp[i] = max(dp[i - 1] + nums[i], nums[i])
    int pre_value = 0;
    int ans = nums[0];
    for (int val : nums) {
      pre_value = std::max(val, val + pre_value);
      ans = std::max(ans, pre_value);
    }
    return ans;
  }
};