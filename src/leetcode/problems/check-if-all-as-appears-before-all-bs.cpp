#include "leetcode/problems/check-if-all-as-appears-before-all-bs.h"

namespace leetcode {
namespace problem_2124 {

namespace {

bool checkStringImpl(std::string s) {
  int lastA = -1;
  int firstB = -1;
  const int n = static_cast<int>(s.size());
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'a') {
      lastA = i;
    } else if (firstB == -1) {
      firstB = i;
    }
  }
  return firstB == -1 || lastA < firstB;
}

}  // namespace

CheckIfAllAsAppearsBeforeAllBsSolution::CheckIfAllAsAppearsBeforeAllBsSolution() {
  setMetaInfo({.id = 2124,
               .title = "Check if All A's Appears Before All B's",
               .url = "https://leetcode.com/problems/check-if-all-as-appears-before-all-bs/"});
  registerStrategy({.name = "single-scan",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(1)",
                    .tags = {"String", "Single Pass"}},
                   checkStringImpl);
}

bool CheckIfAllAsAppearsBeforeAllBsSolution::checkString(std::string s) {
  return getSolution()(std::move(s));
}

}  // namespace problem_2124
}  // namespace leetcode
