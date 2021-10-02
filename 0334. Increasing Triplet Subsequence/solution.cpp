class Solution {
public:
  bool increasingTriplet(vector<int>& nums) {
    // 在遍历时寻找最小和第二小的值：
    // 最小值为数组首元素，如果某个元素比最小值小，则它成为最小值
    // 否则，如果该元素小于第二小的元素，则它成为第二小的元素
    // 否则，该元素同时大于最小值和第二小的值，则存在长度为 3 的子序列

    // 巧妙思路：当遍历到第 i 个元素时，若 nums[i] 比当前的最小值还小，
    // 则它成为最小值，这会导致最小值出现在第二小的值之后吗？
    // 实际上并不会。当后续出现比第二小的值大的元素时，则该元素在第二小的元素前，
    // 而第二小的元素前一定存在比它小的元素（否则它不会成为第二小的元素），
    // 因此必然存在递增子序列
    int _first = std::numeric_limits<int>::max(), _second = std::numeric_limits<int>::max();
    for (int val : nums) {
      if (val <= _first) {
        _first = val;
      } else if (val <= _second) {
        _second = val;
      } else
        return true;
    }
    return false;
  }
};