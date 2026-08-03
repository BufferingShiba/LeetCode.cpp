#include "leetcode/problems/reverse-integer.h"

namespace leetcode {
namespace problem_7 {

static int solution1(int x) {
  int result = 0;
  while (x != 0) {
    int digit = x % 10;
    // Check overflow before updating result.
    // result * 10 + digit must stay within [INT_MIN, INT_MAX].
    if (result > INT_MAX / 10 ||
        (result == INT_MAX / 10 && digit > INT_MAX % 10)) {
      return 0;
    }
    if (result < INT_MIN / 10 ||
        (result == INT_MIN / 10 && digit < INT_MIN % 10)) {
      return 0;
    }
    result = result * 10 + digit;
    x /= 10;
  }
  return result;
}

ReverseIntegerSolution::ReverseIntegerSolution() {
  setMetaInfo({
      .id = 7,
      .title = "Reverse Integer",
      .url = "https://leetcode.com/problems/reverse-integer"
  });
  registerStrategy({.name = "Brute Force"}, solution1);
}

int ReverseIntegerSolution::reverse(int x) {
  return getSolution()(x);
}

}  // namespace problem_7
}  // namespace leetcode
