class Solution {
public:
  void rotate(vector<vector<int>>& matrix) {
    int side_size = matrix.size();
    int temp_size = side_size - 1;
    for (int i = 0; i < side_size / 2; ++i) {
      for (int j = i; j < temp_size - i; ++j) {
        int temp = matrix[i][j];
        matrix[i][j] = matrix[temp_size - j][i];
        matrix[temp_size - j][i] = matrix[temp_size - i][temp_size - j];
        matrix[temp_size - i][temp_size - j] = matrix[j][temp_size - i];
        matrix[j][temp_size - i] = temp;
      }
    }
  }
};