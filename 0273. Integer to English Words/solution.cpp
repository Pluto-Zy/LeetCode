#define GENERATE(base, str)                       \
  if (num > base - 1) {                           \
    result += _three_digits(num / base) + str;    \
  if (num %= base) {                              \
    result += ' ';                                \
  }                                               \
  else                                            \
    return result;                                \
  }

class Solution {
public:
  Solution()
    : _words_first {
      "One",      "Two",        "Three",    "Four",     "Five", 
      "Six",      "Seven",      "Eight",    "Nine",     "Ten",
      "Eleven",   "Twelve",     "Thirteen", "Fourteen", "Fifteen",
      "Sixteen",  "Seventeen",  "Eighteen", "Nineteen"
    }, _words_second {
      "Twenty",   "Thirty",     "Forty",    "Fifty",    "Sixty",
      "Seventy",  "Eighty",     "Ninety"
    } { }

  string numberToWords(int num) {
    if (!num)
      return "Zero";
    std::string result;
    GENERATE(1000000000, " Billion")
    GENERATE(1000000,    " Million")
    GENERATE(1000,       " Thousand")
    GENERATE(1,          "")
    return result;
  }
private:
  std::string _words_first[19];
  std::string _words_second[8];

  std::string _three_digits(unsigned num) {
    if (!num)
      return "";
    std::string result;
    if (unsigned hundred = num / 100) {
      result += _words_first[hundred - 1] + " Hundred";
      num %= 100;
      if (num) {
        result += ' ';
      }
      else
        return result;
    }
    if (num < 20) {
      result += _words_first[num - 1];
    }
    else {
      result += _words_second[num / 10 - 2];
      num %= 10;
      if (num)
        result += ' ' + _words_first[(num % 10) - 1];
    }
    return result;
  }
};