#include "leetcode/problems/apply-bitwise-operations-to-make-strings-equal.h"

#include <algorithm>

namespace leetcode {
namespace problem_2546 {

static bool solution1(string s, string target) {
  bool sHasOne = std::count(s.begin(), s.end(), '1') > 0;
  bool tHasOne = std::count(target.begin(), target.end(), '1') > 0;
  return sHasOne == tHasOne;
}

ApplyBitwiseOperationsToMakeStringsEqualSolution::ApplyBitwiseOperationsToMakeStringsEqualSolution() {
  setMetaInfo({
      .id = 2546,
      .title = "Apply Bitwise Operations to Make Strings Equal",
      .url = "https://leetcode.com/problems/apply-bitwise-operations-to-make-strings-equal"
  });
  registerStrategy({.name = "Brute Force"}, solution1);
}

bool ApplyBitwiseOperationsToMakeStringsEqualSolution::makeStringsEqual(string s, string target) {
  return getSolution()(s, target);
}

}  // namespace problem_2546
}  // namespace leetcode
