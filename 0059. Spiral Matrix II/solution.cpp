class Solution {
public:
  vector<vector<int>> generateMatrix(int n) {
    std::vector<std::vector<int>> result(n, std::vector<int>(n));
    int start_num = 1;
    for (int i = 0; i < n / 2; ++i) {
      int side_width = n - 2 * i - 1;
      for (int j = 0; j < side_width; ++j) {
        result[i][j + i] = start_num + j; // 上边
        result[i + j][n - 1 - i] = start_num + side_width + j;  // 右边
        result[n - 1 - i][n - 1 - i - j] = start_num + side_width * 2 + j;  // 下边
        result[n - 1 - i - j][i] = start_num + side_width * 3 + j;  // 左边
      }
      start_num += side_width * 4;
    }
    if (start_num == n * n) {
      result[n / 2][n / 2] = start_num;
    }
    return result;
  }
};