class Solution {
public:
  vector<int> productExceptSelf(vector<int>& nums) {
    // 遍历数组时，可以得到当前位置的所有左侧元素的乘积，以及对称位置的所有右侧元素的乘积
    // 每次递增遍历位置时，都只需要前一个位置的乘积，因此空间复杂度为 O(1)
    int _left = 1, _right = 1;
    int _size = nums.size();
    std::vector<int> answer(_size, 1);
    for (int i = 0; i < _size; ++i) {
      answer[i] *= _left;
      answer[_size - i - 1] *= _right;
      _left *= nums[i];
      _right *= nums[_size - i - 1];
    }
    return answer;
  }
};