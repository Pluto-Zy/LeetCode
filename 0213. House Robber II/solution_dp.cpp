class Solution {
public:
  int rob(vector<int>& nums) {
    if (nums.size() == 1)
      return nums[0];
    if (nums.size() == 2)
      return std::max(nums[0], nums[1]);
    return std::max(
      _dp_range_unchecked(nums.begin(), nums.end() - 1),
      _dp_range_unchecked(nums.begin() + 1, nums.end())
    );
  }

  int _dp_range_unchecked(std::vector<int>::const_iterator beg, 
                          std::vector<int>::const_iterator end) {
    // dp[i]: 偷窃第 i 家的最高金额
    // dp[i] = max(dp[i - 2] + nums[i], dp[i - 1])
    // dp[0] = nums[0], dp[1] = max(nums[0], nums[1])
    int _first = *beg++;
    int _second = std::max(_first, *beg++);
    for (; beg != end; ++beg) {
      int temp = std::max(_first + *beg, _second);
      _first = _second;
      _second = temp;
    }
    return _second;
  }
};