class Solution {
public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    // 选取 1 个角落
    // 左上角：向下走和向右走都增大
    // 右上角：向左走减小，向下走增大
    // 左下角：向上走减小，向右走增大
    // 右下角：向上走和向右走都减小
    // 因此选择右上角或左下角。
    // 类似于二叉搜索树，搜索一个值时，如果当前值比目标值大，就往小的方向走，
    // 如果当前值比目标值小，就往大的方向走

    // 从右上角开始
    // i 只会增大，j 只会减小
    for (int i = 0, j = matrix[0].size() - 1; i < matrix.size() && j >= 0;) {
      if (matrix[i][j] < target) {
        ++i;
      } else if (matrix[i][j] > target) {
        --j;
      } else
        return true;
    }
    return false;
  }
};