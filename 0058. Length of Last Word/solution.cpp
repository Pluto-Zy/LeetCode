class Solution {
  public:
    int lengthOfLastWord(string s) {
      int idx = s.size() - 1;
      for (; idx >= 0 && s[idx] == ' '; --idx)
        ;
      int result = 0;
      for (; idx >= 0 && s[idx] != ' '; --idx, ++result)
        ;
      return result;
    }
};