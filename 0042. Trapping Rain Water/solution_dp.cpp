class Solution {
public:
  int trap(vector<int>& height) {
    // left[i] 和 right[i] 分别表示 i 柱子左右两侧的最高点
    // 下标 i 能保存的水的数量为 min(left[i], right[i]) - height[i]
    std::vector<int> left(height.size()), right(height.size());
    for (int i = 0, left_max = 0, right_max = 0; i < height.size(); ++i) {
      left_max = std::max(left_max, height[i]);
      right_max = std::max(right_max, height[height.size() - i - 1]);
      left[i] = left_max;
      right[height.size() - i - 1] = right_max;
    }
    int result = 0;
    for (int i = 0; i < height.size(); ++i) {
      result += std::min(left[i], right[i]) - height[i];
    }
    return result;
  }
};