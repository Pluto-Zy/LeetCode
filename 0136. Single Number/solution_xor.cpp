class Solution {
public:
  int singleNumber(vector<int>& nums) {
    int result = nums.front();
    for (int i = 1; i < nums.size(); ++i)
      result ^= nums[i];
    return result;
  }
};