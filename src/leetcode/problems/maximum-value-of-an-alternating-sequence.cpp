#include "leetcode/problems/maximum-value-of-an-alternating-sequence.h"

namespace leetcode {
namespace problem_3993 {

static long solution1(int n, int s, int m) {
  // n, s >= 1; m >= 1.
  // A valid alternating sequence starts at s. Peaks grow by (m-1) per additional peak.
  // Using the "up-first" pattern (seq[0] < seq[1] > seq[2] < ...), peaks are at
  // odd indices. Peak value: s + k*m - (k-1) = s + 1 + k*(m-1), where k is the
  // (k-th) peak (0-indexed). Number of peaks = n/2.
  if (n == 1) {
    return static_cast<long>(s);
  }
  long peaks = static_cast<long>(n) / 2;
  return static_cast<long>(s) + peaks * (static_cast<long>(m) - 1) + 1;
}

MaximumValueOfAnAlternatingSequenceSolution::MaximumValueOfAnAlternatingSequenceSolution() {
  setMetaInfo({
      .id = 3993,
      .title = "Maximum Value of an Alternating Sequence",
      .url = "https://leetcode.com/problems/maximum-value-of-an-alternating-sequence"
  });
  registerStrategy({.name = "Brute Force", .expected = "Accepted"}, solution1);
}

long MaximumValueOfAnAlternatingSequenceSolution::maximumValue(int n, int s, int m) {
  return getSolution()(n, s, m);
}

}  // namespace problem_3993
}  // namespace leetcode
