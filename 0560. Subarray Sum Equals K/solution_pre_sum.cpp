class Solution {
public:
  int subarraySum(vector<int>& nums, int k) {
    // 前缀和是为了固定某个元素位置的，也就是在前缀和的帮助下，
    // 只需要从开头遍历即可。否则，就需要利用 i 和 j 两个循环变量，
    // 进行 O(n^2) 的嵌套遍历。
    // [i, j) 范围内的子数组和为 pre[j] - pre[i]
    // 因此，计算和为 k 的子数组数量，也就是计算 pre[j] - pre[i] 的值为 k 的子数组数量。
    // 这里依旧是 i 和 j 两层嵌套，因此使用哈希表减少一层循环：
    // 遍历时同时计算前缀和，并把当前前缀和保存到哈希表中，从而直接就能获取值为 pre[j] - k 的前缀个数了。
    std::unordered_map<int, int> _pre_map;
    int _pre = 0;
    int _result = 0;
    for (int val : nums) {
      _pre += val;
      if (_pre == k) {
        ++_result;
      }
      auto iter = _pre_map.find(_pre - k);
      if (iter != _pre_map.end())
        _result += iter->second;
      ++_pre_map[_pre];
    }
    return _result;
  }
};