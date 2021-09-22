class Solution {
public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    std::vector<std::vector<int>> result;
    for (int first = 0; first < nums.size(); ++first) {
      if (first != 0 && nums[first] == nums[first - 1])
        continue;
      for (int second = first + 1, third = nums.size() - 1; second < third;) {
        if (second != first + 1 && nums[second] == nums[second - 1]) {
          ++second;
          continue;
        }
        if (third != nums.size() - 1 && nums[third] == nums[third + 1]) {
          --third;
          continue;
        }
        
        int temp = nums[first] + nums[second] + nums[third];
        if (temp > 0) {
          --third;
        } else if (temp < 0) {
          ++second;
        } else {
          result.emplace_back(std::vector<int>{nums[first], nums[second], nums[third]});
          ++second;
        }
      }
    }
    return result;
  }
};