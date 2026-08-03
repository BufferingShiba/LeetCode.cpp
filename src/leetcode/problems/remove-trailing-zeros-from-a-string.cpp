#include "leetcode/problems/remove-trailing-zeros-from-a-string.h"

namespace leetcode {
namespace problem_2710 {

namespace {

std::string removeTrailingZerosImpl(std::string num) {
  size_t end = num.size();
  while (end > 0 && num[end - 1] == '0') {
    --end;
  }
  return num.substr(0, end);
}

}  // namespace

RemoveTrailingZerosFromAStringSolution::RemoveTrailingZerosFromAStringSolution() {
  setMetaInfo({.id = 2710,
               .title = "Remove Trailing Zeros From a String",
               .url = "https://leetcode.com/problems/remove-trailing-zeros-from-a-string/"});
  registerStrategy(
      {"trailing_zeros_scan",
       "Accepted",
       "O(n)",
       "O(n)",
       {"String"}},
      removeTrailingZerosImpl);
}

std::string RemoveTrailingZerosFromAStringSolution::removeTrailingZeros(
    std::string num) {
  return getSolution()(std::move(num));
}

}  // namespace problem_2710
}  // namespace leetcode
