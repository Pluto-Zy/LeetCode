class Solution {
  public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
      int width = 0;
      auto beg = words.cbegin();
      std::vector<std::string> result;
      for (auto iter = words.cbegin(); iter != words.cend(); ++iter) {
        if (iter->size() > maxWidth - width) {
          result.emplace_back(_pack_strings(beg, iter, maxWidth, width - 1));
          width = 0;
          beg = iter;
        }
        // Why do we need this `if`?
        // ["ab", "cd"], where maxWidth = 5
        // for the last word `"cd"`
        // Why not uses `else if` here?
        // Consider the situation: ["a", "bcd"], where maxWidth = 3
        if (iter->size() == maxWidth - width) {
          result.emplace_back(_pack_strings(beg, iter + 1, maxWidth, maxWidth));
          width = 0;
          beg = iter + 1;
          continue;
        }
        width += iter->size() + 1;
      }
      if (beg != words.cend())
        result.emplace_back(_pack_tail(beg, words.cend(), maxWidth));
      return result;
    }

    std::string _pack_strings(std::vector<std::string>::const_iterator beg, std::vector<std::string>::const_iterator end, int max_width, int cur_width) {
      if (end - beg == 1) {
        return *beg + std::string(max_width - cur_width, ' ');
      }
      int count = end - beg - 1;
      int space_width = (max_width - cur_width) / count;
      int big_space_count = max_width - cur_width - space_width * count;
      std::string result;
      result.reserve(max_width);
      for (int i = 0; i < big_space_count; ++i, ++beg) {
        result += *beg;
        result += std::string(space_width + 2, ' ');
      }
      for (int i = 0; i < count - big_space_count; ++i, ++beg) {
        result += *beg;
        result += std::string(space_width + 1, ' ');
      }
      result += *beg;
      return result;
    }

    std::string _pack_tail(std::vector<std::string>::const_iterator beg, std::vector<std::string>::const_iterator end, int max_width) {
      std::string result;
      result.reserve(max_width);
      result += *beg++;
      for (; beg != end; ++beg) {
        result += ' ';
        result += *beg;
      }
      if (result.size() != max_width)
        result += std::string(max_width - result.size(), ' ');
      return result;
    }
};