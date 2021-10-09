class SummaryRanges {
public:
  SummaryRanges() = default;
  
  void addNum(int val) {
    // 加入一个 val 的几种情况：
    // 1. 若存在区间 [a, b]，满足 a <= val <= b，那么不修改任何区间
    // 2. 否则，若存在区间 [a, b] 和 [c, d]（其中 b < c），满足 val = b + 1 = c - 1，则得到新的区间 [a, d]
    // 3. 否则，若存在区间 [a, b] 满足 val = b + 1，则得到新的区间 [a, val]
    // 4. 否则，若存在区间 [a, b] 满足 val + 1 = a，则得到新的区间 [val, b]
    // 5. 否则，加入新的区间 [val, val]
    // 使用 std::map（有序关联容器），能查找到这样的区间
    // std::map::lower_bound：返回首个 >= 给定 key 的元素迭代器
    // std::map::upper_bound，返回首个 >  给定 key 的元素迭代器
    if (_intervals.empty()) {
      _intervals[val] = val;
      return;
    }

    auto _lower = _intervals.upper_bound(val);
    auto _upper = (_lower == _intervals.begin() ? _lower : _lower--);
    if (_lower->first <= val && _lower->second >= val)
      return;
    if (_upper != _intervals.end()) {
      if (_lower->second + 1 == val && _upper->first - 1 == val) {
        _lower->second = _upper->second;
        _intervals.erase(_upper);
        return;
      }
      if (_upper->first - 1 == val) {
        _intervals.insert(_lower, {val, _upper->second});
        // 对于关联容器，插入元素不会导致迭代器失效
        _intervals.erase(_upper);
        return;
      }
    }
    if (_lower->second + 1 == val)
      _lower->second = val;
    else
      _intervals.insert(_lower, {val, val});
  }
  
  vector<vector<int>> getIntervals() {
    std::vector<std::vector<int>> result;
    result.reserve(_intervals.size());
    for (auto iter = _intervals.begin(); iter != _intervals.end(); ++iter) {
      result.emplace_back(std::vector<int>{iter->first, iter->second});
    }
    return result;
  }
private:
  std::map<int, int> _intervals;
  // 区间 [a, b] 保存为 key = a, value = b
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */