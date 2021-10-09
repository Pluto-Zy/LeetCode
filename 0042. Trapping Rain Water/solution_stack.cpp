class Solution {
public:
  int trap(vector<int>& height) {
    // 单调栈：从栈顶到栈底，元素逐渐增大
    // 栈中保存 height 的索引
    std::stack<int> _stack;
    _stack.push(0);
    int result = 0;
    for (int i = 1; i < height.size(); ++i) {
      while (_stack.size() > 1 && height[_stack.top()] <= height[i]) {
        int _bottom = height[_stack.top()];
        _stack.pop();
        result += (std::min(height[i], height[_stack.top()]) - _bottom) * (i - _stack.top() - 1);
      }
      if (_stack.size() == 1 && height[_stack.top()] <= height[i])
        _stack.pop();
      _stack.push(i);
    }
    return result;
  }
};