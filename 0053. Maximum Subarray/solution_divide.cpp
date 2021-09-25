class Solution {
    using iter_t = std::vector<int>::iterator;
  public:
    int maxSubArray(vector<int>& nums) {
      return maxSubSeq(nums.begin(), nums.end());
    }
  private:
    int maxCrossSeq(iter_t beg, iter_t mid, iter_t end) {
      int left_max = *mid, right_max = left_max;
      int cur_ans = 0;
      for (auto iter = mid; iter >= beg; --iter) {
        cur_ans += *iter;
        left_max = std::max(left_max, cur_ans);
      }
      cur_ans = 0;
      for (auto iter = mid; iter != end; ++iter) {
        cur_ans += *iter;
        right_max = std::max(right_max, cur_ans);
      }
      return left_max + right_max - *mid;
    }

    int maxSubSeq(iter_t beg, iter_t end) {
      if (end - beg == 1)
        return *beg;
      auto mid = beg + (end - beg) / 2;
      return std::max ({
        maxSubSeq(beg, mid),
        maxSubSeq(mid, end),
        maxCrossSeq(beg, mid, end)
      });
    }
};