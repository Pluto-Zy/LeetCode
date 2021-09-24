class Solution {
public:
  bool canJump(vector<int>& nums) {
    int max_distance = nums[0];
    int i = 1;
    for (; i <= max_distance && i < nums.size(); ++i) {
      max_distance = std::max(max_distance, nums[i] + i);
    }
    return i == nums.size();
  }
};