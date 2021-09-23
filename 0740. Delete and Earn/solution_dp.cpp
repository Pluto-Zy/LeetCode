class Solution {
public:
  /*
  * 关键思路：
  * 如果值为 a 的元素有多个，那么删除一个 a 后，
  * 所有的 a - 1 和 a + 1 都已不存在，此时应该把剩余的 a
  * 全部删除。因此，不关心具体 nums[i] 的值，而是关心所有
  * 与 nums[i] 的值相同的元素的**和**。
  * 
  * 动态规划：
  * dp[i]: 删除 nums[i] 后能获得的最大点数
  * 对数组排序，则排序后，相邻值相差超过 1 的元素不会互相影响。
  * 也就是**分段 dp**.
  */
  int deleteAndEarn(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    std::vector<int> sum{ nums[0] };
    int result = 0;
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] == nums[i - 1])
        sum.back() += nums[i];
      else if (nums[i] == nums[i - 1] + 1)
        sum.push_back(nums[i]);
      else {
        result += dp(std::move(sum));
        sum = std::vector<int>{ nums[i] };
      }
    }
    result += dp(std::move(sum));
    return result;
  }
private:
  /*
  * sum: 保存了连续序列中相同元素的和
  */
  int dp(std::vector<int> sum) {
    // dp[i]: 删除 sum[i] 对应元素时的最大点数
    // dp[i] = max(dp[i - 2] + sum[i], dp[i - 1])
    //    dp[i - 2] + sum[i]: 删除不相邻的 i - 2 位置和自身
    //    dp[i - 1]: 删除相邻的 i - 1 位置导致自身被删除
    if (sum.size() == 1)
      return sum[0];
    int _first = sum[0], _second = std::max(sum[0], sum[1]);
    for (std::size_t i = 2; i < sum.size(); ++i) {
      int temp = std::max(_first + sum[i], _second);
      _first = _second;
      _second = temp;
    }
    return _second;
  }
};