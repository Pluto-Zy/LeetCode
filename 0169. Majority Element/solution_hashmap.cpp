class Solution {
public:
  int majorityElement(vector<int>& nums) {
    std::map<int, int> map;
    for (int val : nums) {
      ++map[val];
      if (map[val] > nums.size() / 2)
        return val;
    }
    return 0;
  }
};