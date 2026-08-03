#include "leetcode/problems/largest-even-number.h"

namespace leetcode {
namespace problem_3798 {
namespace {

std::string largestEvenImpl(const std::string& s) {
  // The result must be a subsequence preserving order. An even number must end
  // in '2'. Keeping every character up to and including the last '2' gives the
  // maximum number of digits (all digits positive, so more digits = larger),
  // and cannot be beaten by deleting middle characters which would shorten it.
  std::size_t last2 = s.find_last_of('2');
  if (last2 == std::string::npos) return "";
  return s.substr(0, last2 + 1);
}

}  // namespace

LargestEvenNumberSolution::LargestEvenNumberSolution() {
  setMetaInfo({.id = 3798,
               .title = "Largest Even Number",
               .url =
                   "https://leetcode.com/problems/largest-even-number/"});
  registerStrategy({.name = "GreedySuffix",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(n)",
                    .tags = {"String", "Greedy"}},
                   largestEvenImpl);
}

std::string LargestEvenNumberSolution::largestEven(std::string s) {
  return getSolution()(std::move(s));
}

}  // namespace problem_3798
}  // namespace leetcode
