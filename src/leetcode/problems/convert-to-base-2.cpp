#include "leetcode/problems/convert-to-base-2.h"

#include <algorithm>
#include <string>

namespace leetcode {
namespace problem_1017 {

static std::string baseNeg2Impl(int n) {
  if (n == 0) {
    return "0";
  }

  std::string result;
  while (n != 0) {
    int remainder = n % (-2);
    n /= -2;
    if (remainder < 0) {
      remainder += 2;
      n += 1;
    }
    result += static_cast<char>('0' + remainder);
  }

  std::reverse(result.begin(), result.end());
  return result;
}

ConvertToBase2Solution::ConvertToBase2Solution() {
  setMetaInfo({.id = 1017, .title = "Convert to Base -2",
               .url = "https://leetcode.com/problems/convert-to-base-2/"});
  registerStrategy(
      {.name = "Iterative division",
       .expected = "Accepted",
       .time_complexity = "O(log n)",
       .space_complexity = "O(log n)",
       .tags = {"Math"}},
      baseNeg2Impl);
}

}  // namespace problem_1017
}  // namespace leetcode
