class Solution {
public:
  int majorityElement(vector<int>& nums) {
    // 投票法：
    // candidate: 胜选者
    // count: 票数
    // 投票：count + 1；反对：count - 1
    // count 为 0 时换届选举
    // 每个元素都给自己投同意票，给其他人投反对票
    // 多数元素最终必然能胜选
    int candidate = nums[0];
    int count     = 1;
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] == candidate)
        ++count;
      else {
        --count;
        if (!count) {
          candidate = nums[i];
          count = 1;
        }
      }
    }
    return candidate;
  }
};