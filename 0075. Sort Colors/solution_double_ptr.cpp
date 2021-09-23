class Solution {
public:
  void sortColors(vector<int>& nums) {
    auto iter_0 = nums.begin(), iter_2 = nums.end() - 1;
    for (auto iter = nums.begin(); iter <= iter_2; ++iter) {
      if (*iter == 2) {
        while (*iter_2 == 2 && iter_2 != iter)  
          --iter_2;
        std::swap(*iter, *iter_2--);
      }
      if (*iter == 0)
        std::swap(*iter, *iter_0++);
    }
  }
};