#include "leetcode/problems/generate-a-string-with-characters-that-have-odd-counts.h"

namespace leetcode {
namespace problem_1374 {

static std::string generateTheStringImpl(int n) {
  if (n % 2 == 1) {
    // n is odd: all 'a'
    return std::string(n, 'a');
  }
  // n is even: n-1 'a' + 1 'b'
  return std::string(n - 1, 'a') + 'b';
}

GenerateAStringWithCharactersThatHaveOddCountsSolution::GenerateAStringWithCharactersThatHaveOddCountsSolution() {
  setMetaInfo({.id = 1374,
               .title = "Generate a String With Characters That Have Odd Counts",
               .url = "https://leetcode.com/problems/generate-a-string-with-characters-that-have-odd-counts/"});

  registerStrategy({.name = "OddEven",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(n)",
                    .tags = {"String"}},
                   generateTheStringImpl);

  setDefaultStrategy();
}

std::string GenerateAStringWithCharactersThatHaveOddCountsSolution::generateTheString(int n) {
  return getSolution()(n);
}

}  // namespace problem_1374
}  // namespace leetcode
