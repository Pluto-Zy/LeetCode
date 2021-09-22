class Solution {
public:
  vector<vector<int>> subsets(vector<int>& nums) {
    unsigned int count = 1 << nums.size();
    std::vector<std::vector<int>> result;
    result.reserve(count);
    for (unsigned int i = 0; i < count; ++i) {
      std::vector<int> temp;
      for (unsigned int j = 0, src = i; j < nums.size() && src; src >>= 1, ++j) {
        if (src & 1) {
          temp.push_back(nums[j]);
        }
      }
      result.emplace_back(std::move(temp));
    }
    return result;
  }
};