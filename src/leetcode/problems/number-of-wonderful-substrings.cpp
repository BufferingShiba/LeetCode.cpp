#include "leetcode/problems/number-of-wonderful-substrings.h"

#include <array>
#include <string>

namespace leetcode::problem_1915 {

namespace {

long long wonderfulSubstringsImpl(const std::string& word) {
  std::array<long long, 1024> count{};
  count[0] = 1;  // empty prefix mask
  int mask = 0;
  long long ans = 0;
  for (char ch : word) {
    mask ^= (1 << (ch - 'a'));
    // 0 odd letters: found previous prefixes with the same mask
    ans += count[mask];
    // 1 odd letter: flip exactly one bit
    for (int k = 0; k < 10; ++k) {
      ans += count[mask ^ (1 << k)];
    }
    ++count[mask];
  }
  return ans;
}

}  // namespace

NumberOfWonderfulSubstringsSolution::NumberOfWonderfulSubstringsSolution() {
  setMetaInfo({.id = 1915,
               .title = "Number of Wonderful Substrings",
               .url = "https://leetcode.com/problems/number-of-wonderful-substrings/"});

  registerStrategy({.name = "prefix-bitmask",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(1)",
                    .tags = {"Hash Table", "String", "Bit Manipulation", "Prefix Sum"}},
                   wonderfulSubstringsImpl);
}

long long NumberOfWonderfulSubstringsSolution::wonderfulSubstrings(std::string word) {
  return getSolution()(std::move(word));
}

}  // namespace leetcode::problem_1915
