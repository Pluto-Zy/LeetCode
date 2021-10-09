class SummaryRanges {
public:
  SummaryRanges() : _bits{} { }
  
  void addNum(int val) {
    auto idx = static_cast<std::make_unsigned_t<decltype(val)>>(val);
    _bits[idx >> 3] |= 1 << (idx - ((idx >> 3) << 3));
  }
  
  vector<vector<int>> getIntervals() {
    std::vector<std::vector<int>> result;
    bool last = false;
    bool flag = false;
    for (std::size_t i = 0; i < sizeof(_bits); ++i) {
      for (std::uint8_t val = _bits[i], idx = 0; idx < 8; val >>= 1, ++idx) {
        flag = val & 1;
        if (!last && flag) {
          result.emplace_back(std::vector<int>(2));
          result.back()[0] = (i << 3) + idx;
        }
        else if (last && !flag) {
          result.back()[1] = (i << 3) + idx - 1;
        }
        last = flag;
        if (!val)
          break;
      }
    }
    return result;
  }
private:
  std::uint8_t _bits[10000 / 8 + 1];
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */