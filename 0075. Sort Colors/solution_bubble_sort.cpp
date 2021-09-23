class Solution {
public:
  void sortColors(vector<int>& nums) {
    int bubble[3]{};
    for (int val : nums)
      ++bubble[val];
    auto iter = nums.begin();
    iter = std::fill_n(iter, bubble[0], 0);
    iter = std::fill_n(iter, bubble[1], 1);
    iter = std::fill_n(iter, bubble[2], 2);
  }
};