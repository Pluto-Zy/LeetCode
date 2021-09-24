class Solution {
public:
  int jump(vector<int>& nums) {
    // 贪心：每次都尝试跳跃到最远的位置
    // 从点 p 开始跳跃，能跳跃的最大距离是 p + nums[p]
    // 在 [p, p + nums[p]] 的范围内，找到能跳到的最远位置
    // 也就是说，在 [p, p + nums[p]] 中，肯定要跳跃一次
    // 找到最大位置的过程直接结合在遍历 nums 的过程中，因此
    // 需要保存 p + nums[p] 的位置（记为 q），当遍历到达 q 时，
    // 此时的最大位置 max_distance，就是 [p, p + nums[p]] 中能
    // 跳到的最远位置，增加 1 次跳跃次数（也就是 [p, p + nums[p]] 
    // 中的那次跳跃），并标记下一个最远跳跃位置为 max_distance
    int max_distance = 0; // 当前遍历能跳跃的最远位置
    int end_pos = 0;      // 一次遍历的结束点（q）
    int result = 0;
    // 处于最后一个位置时，无需继续跳跃
    for (int i = 0; i < nums.size() - 1; ++i) {
      // 由于 q 点是闭区间，因此，跳跃的最大位置也可能出现在 q 点
      // 因此先判断最大值
      max_distance = std::max(i + nums[i], max_distance);
      if (i == end_pos) {
        // 说明 [p, p + nums[p]] 的范围已遍历完，得到了最大位置
        ++result;
        end_pos = max_distance; // 更新新的 q 值
      }
    }
    return result;
  }
};