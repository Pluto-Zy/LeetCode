class Solution {
public:
  vector<int> getRow(int rowIndex) {
    std::vector<int> result(rowIndex + 1);
    result[0] = 1;
    for (int i = 1; i <= rowIndex / 2; ++i) {
      result[i] = static_cast<unsigned long long>(result[i - 1]) * (rowIndex - i + 1) / i;
    }
    for (int i = rowIndex / 2 + 1; i <= rowIndex; ++i) {
      result[i] = result[rowIndex - i];
    }
    return result;
  }
};