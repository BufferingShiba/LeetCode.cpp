#include "leetcode/problems/hash-divided-string.h"

#include <string>

namespace leetcode {
namespace problem_3271 {

namespace {

std::string stringHashImpl(std::string s, int k) {
  const int n = static_cast<int>(s.size());
  std::string result;
  result.reserve(n / k);

  for (int i = 0; i < n; i += k) {
    int sum = 0;
    for (int j = 0; j < k; ++j) {
      sum += s[i + j] - 'a';
    }
    result.push_back(static_cast<char>('a' + sum % 26));
  }

  return result;
}

}  // namespace

std::string HashDividedStringSolution::stringHash(std::string s, int k) {
  return getSolution()(std::move(s), k);
}

HashDividedStringSolution::HashDividedStringSolution() {
  setMetaInfo({.id = 3271,
               .title = "Hash Divided String",
               .url = "https://leetcode.com/problems/hash-divided-string/"});

  registerStrategy(
      {.name = "direct_simulation",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(n/k)",
       .tags = {"String", "Simulation"}},
      stringHashImpl);
}

}  // namespace problem_3271
}  // namespace leetcode
