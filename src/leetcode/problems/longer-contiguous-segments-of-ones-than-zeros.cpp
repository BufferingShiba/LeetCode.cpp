#include "leetcode/problems/longer-contiguous-segments-of-ones-than-zeros.h"

namespace leetcode {
namespace problem_1869 {

static bool solution1(string s) {
  int maxOnes = 0, maxZeros = 0;
  int curOnes = 0, curZeros = 0;
  for (char c : s) {
    if (c == '1') {
      curOnes++;
      curZeros = 0;
      maxOnes = std::max(maxOnes, curOnes);
    } else {
      curZeros++;
      curOnes = 0;
      maxZeros = std::max(maxZeros, curZeros);
    }
  }
  return maxOnes > maxZeros;
}

LongerContiguousSegmentsOfOnesThanZerosSolution::LongerContiguousSegmentsOfOnesThanZerosSolution() {
  setMetaInfo({
      .id = 1869,
      .title = "Longer Contiguous Segments of Ones than Zeros",
      .url = "https://leetcode.com/problems/longer-contiguous-segments-of-ones-than-zeros"
  });
  registerStrategy({.name = "Brute Force", .time_complexity = "O(n)", .space_complexity = "O(1)", .tags = {"String"}}, solution1);
}

bool LongerContiguousSegmentsOfOnesThanZerosSolution::checkZeroOnes(string s) {
  return getSolution()(s);
}

}  // namespace problem_1869
}  // namespace leetcode
