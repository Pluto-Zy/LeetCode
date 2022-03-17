class Solution {
public:
  int maxNumberOfBalloons(string text) {
    constexpr std::size_t a_idx = static_cast<std::size_t>('a' - 'a');
    constexpr std::size_t b_idx = static_cast<std::size_t>('b' - 'a');
    constexpr std::size_t l_idx = static_cast<std::size_t>('l' - 'a');
    constexpr std::size_t o_idx = static_cast<std::size_t>('o' - 'a');
    constexpr std::size_t n_idx = static_cast<std::size_t>('n' - 'a');

    unsigned short count[26] {};
    for (char ch : text) {
      ++count[ch - 'a'];
    }
    return std::min<int>({
      count[a_idx], count[b_idx], count[n_idx],
      count[l_idx] / 2, count[o_idx] / 2
    });
  }
};