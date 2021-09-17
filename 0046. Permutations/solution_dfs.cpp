class Solution {
  public:
    vector<vector<int>> permute(vector<int>& nums) {
      std::vector<std::vector<int>> result;
      result.reserve(nums.size() * (nums.size() - 1));
      std::vector<int> temp;
      dfs(result, nums, temp, 0);
      return result;
    }

    void dfs(std::vector<std::vector<int>>& result, std::vector<int>& nums, std::vector<int>& current, int idx) {
      using std::swap;
      if (current.size() == nums.size()) {
        result.push_back(current);
      } else {
        for (int i = idx; i < nums.size(); ++i) {
          current.push_back(nums[i]);
          swap(nums[idx], nums[i]);
          dfs(result, nums, current, idx + 1);
          current.pop_back();
          swap(nums[idx], nums[i]);
        }
      }
    }
};