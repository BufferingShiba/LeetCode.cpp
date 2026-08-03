#include "leetcode/problems/number-of-segments-in-a-string.h"

namespace leetcode {
namespace problem_434 {

namespace {

int countSegmentsImpl(const std::string& s) {
  int count = 0;
  for (size_t i = 0; i < s.size(); ++i) {
    if (s[i] != ' ' && (i == 0 || s[i - 1] == ' ')) {
      ++count;
    }
  }
  return count;
}

}  // namespace

NumberOfSegmentsInAStringSolution::NumberOfSegmentsInAStringSolution() {
  setMetaInfo({.id = 434,
               .title = "Number of Segments in a String",
               .url = "https://leetcode.com/problems/number-of-segments-in-a-string/"});
  registerStrategy({.name = "SinglePassCount",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(1)",
                    .tags = {"String"},
                    .notes = "Count a non-space char that follows a space or is at the start."},
                   countSegmentsImpl);
}

int NumberOfSegmentsInAStringSolution::countSegments(std::string s) {
  return getSolution()(std::move(s));
}

}  // namespace problem_434
}  // namespace leetcode
