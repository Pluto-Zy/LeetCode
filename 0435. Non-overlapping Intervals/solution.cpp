class Solution {
public:
  int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    // 确定不重叠区间的最大个数：按照右边界排序
    // 每次选择右边界最靠左的（不重叠）区间，从而为右侧留出更多空间以容纳更多不重叠区间
    // 右边界尽可能小的不重叠区间相当于已经处理了左边界的情况
    std::sort(intervals.begin(), intervals.end(), [](const std::vector<int>& lhs, const std::vector<int>& rhs) {
      return std::tie(lhs[1], lhs[0]) < std::tie(rhs[1], rhs[0]);
    });
    int result = intervals.size() - 1;
    int last_right = intervals[0][1];
    for (int i = 1; i < intervals.size(); ++i) {
      if (intervals[i][0] >= last_right) {
        --result;
        last_right = intervals[i][1];
      }
    }
    return result;
  }
};