#include "leetcode/problems/string-to-integer-atoi.h"

namespace leetcode {
namespace problem_8 {

static int solution1(string s) {
  int i = 0;
  const int n = static_cast<int>(s.size());
  // 1. Skip leading whitespace
  while (i < n && s[i] == ' ') {
    ++i;
  }
  // 2. Determine sign
  bool negative = false;
  if (i < n && (s[i] == '+' || s[i] == '-')) {
    negative = (s[i] == '-');
    ++i;
  }
  // 3. Convert digits
  long long result = 0;
  while (i < n && s[i] >= '0' && s[i] <= '9') {
    result = result * 10 + (s[i] - '0');
    if (negative && result > 2147483648LL) {
      result = 2147483648LL;  // cap negative magnitude
    } else if (!negative && result > 2147483647LL) {
      result = 2147483647LL;  // cap positive magnitude
    }
    ++i;
  }
  // 4. Apply sign and return
  if (negative) {
    result = -result;
  }
  return static_cast<int>(result);
}

StringToIntegerAtoiSolution::StringToIntegerAtoiSolution() {
  setMetaInfo({
      .id = 8,
      .title = "String to Integer (atoi)",
      .url = "https://leetcode.com/problems/string-to-integer-atoi"
  });
  registerStrategy({.name = "Brute Force"}, solution1);
}

int StringToIntegerAtoiSolution::myAtoi(string s) {
  return getSolution()(s);
}

}  // namespace problem_8
}  // namespace leetcode
