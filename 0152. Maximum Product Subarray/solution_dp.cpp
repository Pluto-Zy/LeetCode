class Solution {
public:
  int maxProduct(vector<int>& nums) {
    // 依旧使用最大子序和的思想，但有变化：
    // [-2, 3, -4] 的情况：若使用最大子序和的思想，则 dp 数组为 [-2, 3, -4]
    // 没有考虑 -2 * 3 * -4 实际上是最大的
    // 因为当 dp[2] 看到 dp[1] 为 3 时，3 * -4 比 -4 小。
    // 因此新增加一个 dp_min 数组，存储 “最小子序和”，即 [-2, -6, -4]
    // 每次计算 dp_max 和 dp_min 数组的值时，都计算 3 项。
    int result    = nums[0];
    int _last_max = nums[0];
    int _last_min = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
      // 需要拷贝
      int _cache_max = _last_max, _cache_min = _last_min;
      _last_min = std::min({nums[i], _cache_max * nums[i], _cache_min * nums[i]});
      _last_max = std::max({nums[i], _cache_max * nums[i], _cache_min * nums[i]});
      result = std::max(result, _last_max);
    }
    return result;
  }
};