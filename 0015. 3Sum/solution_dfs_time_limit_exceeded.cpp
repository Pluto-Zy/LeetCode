// 该方法会导致最后几个数据超时，仅仅记录于此
class Solution {
  std::vector<int> _candidate;
public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    _candidate = std::move(nums); // It's not so good for application.
    std::sort(_candidate.begin(), _candidate.end());
    std::vector<std::vector<int>> result;
    std::vector<int> temp;
    dfs(result, 0, temp, 0);
    return result;
  }

  void dfs(std::vector<std::vector<int>>& result, int sum, std::vector<int>& cur, int idx) {
    if (cur.size() == 3 && sum == 0) {
      result.push_back(cur);
      return;
    }
    int _need_count = 2 - cur.size();
    if (cur.size() == 3 || idx == _candidate.size() || _need_count + idx == _candidate.size())
      return;
    if (idx != _candidate.size() - 1 && sum + _candidate[idx] + _need_count * _candidate[idx + 1] > 0)
      return;
    cur.push_back(_candidate[idx]);
    dfs(result, sum + _candidate[idx], cur, idx + 1);
    cur.pop_back();
    for (int i = idx + 1; i < _candidate.size(); ++i) {
      if (_candidate[i] == _candidate[i - 1])
        continue;
      if (i != _candidate.size() - 1 && sum + _candidate[i] + _need_count * _candidate[i + 1] > 0)
        return;
      if (i != _candidate.size() - 1 && sum + _candidate[i] + _need_count * _candidate.back() < 0)
        continue;
      cur.push_back(_candidate[i]);
      dfs(result, sum + _candidate[i], cur, i + 1);
      cur.pop_back();
    }
  }
};