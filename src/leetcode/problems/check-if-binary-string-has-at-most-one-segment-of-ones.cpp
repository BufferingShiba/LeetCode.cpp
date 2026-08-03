#include "leetcode/problems/check-if-binary-string-has-at-most-one-segment-of-ones.h"

namespace {

bool checkOnesSegmentImpl(std::string s) {
  for (std::size_t i = 1; i < s.size(); ++i) {
    if (s[i - 1] == '0' && s[i] == '1') {
      return false;
    }
  }
  return true;
}

}  // namespace

namespace leetcode {
namespace problem_1784 {

CheckIfBinaryStringHasAtMostOneSegmentOfOnesSolution::CheckIfBinaryStringHasAtMostOneSegmentOfOnesSolution() {
  setMetaInfo({.id = 1784,
               .title = "Check if Binary String Has at Most One Segment of Ones",
               .url = "https://leetcode.com/problems/check-if-binary-string-has-at-most-one-segment-of-ones/"});
  registerStrategy({.name = "OnePass",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(1)",
                    .tags = {"String"}},
                   checkOnesSegmentImpl);
}

bool CheckIfBinaryStringHasAtMostOneSegmentOfOnesSolution::checkOnesSegment(std::string s) {
  return getSolution()(s);
}

}  // namespace problem_1784
}  // namespace leetcode
