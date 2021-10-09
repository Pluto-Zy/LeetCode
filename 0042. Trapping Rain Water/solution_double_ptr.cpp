class Solution {
public:
  int trap(vector<int>& height) {
    // 双指针：
    // left: 从左侧遍历的索引
    // right: 从右侧遍历的索引
    // left_max: 当前遍历过的左侧元素的最大值
    // right_max: 当前遍历过的右侧元素的最大值
    // left_max 对于 left 来说是可信的，right_max 对于 right 来说是可信的
    // 当 left_max < right_max 时，对于索引为 left 的柱子来说，
    // left_max 就是它左侧柱子的最高点，但 right_max 不是右侧柱子的最高点
    // 若用 right_max' 表示对于 left 的柱子来说实际上的右侧柱子的最高点，则
    // right_max' >= right_max > left_max，因此
    // left 的柱子的取水量取决于 left_max，与 right_max' 无关。
    // 当 left_max >= right_max 时同理
    int left = 0, right = height.size() - 1;
    int left_max = 0, right_max = 0;
    int result = 0;
    for (; left != right;) {
      left_max = std::max(left_max, height[left]);
      right_max = std::max(right_max, height[right]);
      if (left_max < right_max) {
        result += left_max - height[left];
        ++left;
      } else {
        result += right_max - height[right];
        --right;
      }
    }
    return result;
  }
};