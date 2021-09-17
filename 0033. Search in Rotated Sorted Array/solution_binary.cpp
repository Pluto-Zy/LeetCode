class Solution {
public:
    int search(vector<int>& nums, int target) {
      std::vector<int>::iterator beg = nums.begin(), end = nums.end(), mid;
      while (beg != end) {
        mid = beg + (end - beg) / 2;
        if (*mid == target)
          return mid - nums.begin();
        if (*mid < *beg) {
          // 旋转位置在前半段
          if (*mid > target || *beg <= target)
            end = mid;
          else
            beg = mid + 1;
        } else {
          // 旋转位置在后半段
          if (target < *mid && target >= *beg)
            end = mid;
          else
            beg = mid + 1;
        }
      }
      return -1;
    }
};