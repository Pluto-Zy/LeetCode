class Solution {
public:
  int maxSubarraySumCircular(vector<int>& nums) {
    // 类似于 53. 最大子序和
    // 使用 53 题的 dp 方法计算整个 nums 上的最大值
    // 接着考虑跨越边界环形回绕的情况。本质上是从整个数组中挖掉一段 “和最小” 的子序列
    // 因此，可以在一次遍历中同时获取最大子序和以及最小子序和
    int sum = 0;  // 整个数组的和
    int dp_max_last = 0;  // 滚动数组：求取最大和时的 dp 上一项
    int max_sum = nums[0];// 最大子序和
    int dp_min_last = 0;  // 滚动数组，求取最小和时的 dp 上一项
    int min_sum = nums[0];// 最小子序和
    for (int val : nums) {
      sum        += val;
      dp_max_last = std::max(dp_max_last + val, val);
      max_sum     = std::max(dp_max_last, max_sum);
      dp_min_last = std::min(dp_min_last + val, val);
      min_sum     = std::min(dp_min_last, min_sum);
    }
    // 全为负数的情况，此时可能导致整个数组都被挖去
    if (sum == min_sum)
      return max_sum;
    return std::max(max_sum, sum - min_sum);
  }
};