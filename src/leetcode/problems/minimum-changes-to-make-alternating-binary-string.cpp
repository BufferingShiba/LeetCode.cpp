#include "leetcode/problems/minimum-changes-to-make-alternating-binary-string.h"

namespace leetcode {
namespace problem_1758 {

static int minOperationsImpl(const std::string& s) {
  int n = s.size();
  int cnt0 = 0;  // changes needed to match "0101..."
  int cnt1 = 0;  // changes needed to match "1010..."
  for (int i = 0; i < n; ++i) {
    char expected0 = (i % 2 == 0) ? '0' : '1';
    char expected1 = (i % 2 == 0) ? '1' : '0';
    if (s[i] != expected0) ++cnt0;
    if (s[i] != expected1) ++cnt1;
  }
  return cnt0 < cnt1 ? cnt0 : cnt1;
}

int MinimumChangesToMakeAlternatingBinaryStringSolution::minOperations(std::string s) {
  return getSolution()(s);
}

MinimumChangesToMakeAlternatingBinaryStringSolution::MinimumChangesToMakeAlternatingBinaryStringSolution() {
  setMetaInfo({.id = 1758, .title = "Minimum Changes To Make Alternating Binary String",
               .url = "https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string/"});
  registerStrategy(
      {.name = "linear",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"String"}},
      minOperationsImpl);
}

}  // namespace problem_1758
}  // namespace leetcode
