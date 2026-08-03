#include "leetcode/problems/check-adjacent-digit-differences.h"

namespace leetcode {
namespace problem_3931 {

namespace {

bool isAdjacentDiffAtMostTwoImpl(std::string s) {
  for (std::size_t i = 0; i + 1 < s.size(); ++i) {
    if (std::abs(static_cast<int>(s[i]) - static_cast<int>(s[i + 1])) > 2) {
      return false;
    }
  }
  return true;
}

}  // namespace

CheckAdjacentDigitDifferencesSolution::CheckAdjacentDigitDifferencesSolution() {
  setMetaInfo({.id = 3931,
               .title = "Check Adjacent Digit Differences",
               .url = "https://leetcode.com/problems/check-adjacent-digit-differences/"});
  registerStrategy({"LinearScan", "Accepted", "O(n)", "O(1)", {"String"}},
                   isAdjacentDiffAtMostTwoImpl);
}

bool CheckAdjacentDigitDifferencesSolution::isAdjacentDiffAtMostTwo(
    std::string s) {
  return getSolution()(std::move(s));
}

}  // namespace problem_3931
}  // namespace leetcode
