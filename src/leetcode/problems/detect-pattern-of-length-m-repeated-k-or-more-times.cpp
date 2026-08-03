#include "leetcode/problems/detect-pattern-of-length-m-repeated-k-or-more-times.h"

#include <vector>

namespace leetcode {
namespace problem_1566 {

namespace {

bool containsPatternImpl(std::vector<int>& arr, int m, int k) {
  const int n = static_cast<int>(arr.size());
  if (n < m * k) {
    return false;
  }
  for (int start = 0; start + m * k <= n; ++start) {
    bool ok = true;
    // Compare each repetition with the first pattern segment.
    for (int rep = 1; rep < k && ok; ++rep) {
      for (int offset = 0; offset < m; ++offset) {
        if (arr[start + rep * m + offset] != arr[start + offset]) {
          ok = false;
          break;
        }
      }
    }
    if (ok) {
      return true;
    }
  }
  return false;
}

}  // namespace

DetectPatternOfLengthMRepeatedKOrMoreTimesSolution::
    DetectPatternOfLengthMRepeatedKOrMoreTimesSolution() {
  setMetaInfo({.id = 1566,
               .title = "Detect Pattern of Length M Repeated K or More Times",
               .url = "https://leetcode.com/problems/detect-pattern-of-length-m-repeated-k-or-more-times/"});
  registerStrategy(
      {"BruteForceEnumeration", "Accepted", "O(n*m*k)", "O(1)",
       {"Array", "Enumeration"}},
      containsPatternImpl);
}

bool DetectPatternOfLengthMRepeatedKOrMoreTimesSolution::containsPattern(
    std::vector<int>& arr, int m, int k) {
  return getSolution()(arr, m, k);
}

}  // namespace problem_1566
}  // namespace leetcode
