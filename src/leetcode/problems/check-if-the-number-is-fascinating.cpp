#include "leetcode/problems/check-if-the-number-is-fascinating.h"

#include <string>
#include <unordered_set>

namespace leetcode {
namespace problem_2729 {

namespace {

bool isFascinatingImpl(int n) {
  std::string s = std::to_string(n) + std::to_string(2 * n) +
                  std::to_string(3 * n);
  if (s.size() != 9) {
    return false;
  }
  std::unordered_set<char> seen;
  for (char c : s) {
    if (c == '0' || seen.count(c) > 0) {
      return false;
    }
    seen.insert(c);
  }
  return true;
}

}  // namespace

CheckIfTheNumberIsFascinatingSolution::CheckIfTheNumberIsFascinatingSolution() {
  setMetaInfo({.id = 2729,
               .title = "Check if The Number is Fascinating",
               .url = "https://leetcode.com/problems/check-if-the-number-is-fascinating/"});

  registerStrategy(
      {.name = "HashSet",
       .expected = "Accepted",
       .time_complexity = "O(1)",
       .space_complexity = "O(1)",
       .tags = {"Hash Table", "Math"}},
      isFascinatingImpl);
}

bool CheckIfTheNumberIsFascinatingSolution::isFascinating(int n) {
  return getSolution()(n);
}

}  // namespace problem_2729
}  // namespace leetcode
