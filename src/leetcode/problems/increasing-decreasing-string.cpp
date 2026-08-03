#include "leetcode/problems/increasing-decreasing-string.h"

namespace leetcode::problem_1370 {

namespace {

std::string sortStringImpl(const std::string& s) {
  std::vector<int> count(26, 0);
  for (char c : s) {
    ++count[c - 'a'];
  }

  std::string result;
  while (result.size() < s.size()) {
    // Increasing pass: smallest to largest.
    for (int i = 0; i < 26; ++i) {
      if (count[i] > 0) {
        result.push_back(static_cast<char>('a' + i));
        --count[i];
      }
    }
    // Decreasing pass: largest to smallest.
    for (int i = 25; i >= 0; --i) {
      if (count[i] > 0) {
        result.push_back(static_cast<char>('a' + i));
        --count[i];
      }
    }
  }
  return result;
}

}  // namespace

std::string IncreasingDecreasingStringSolution::sortString(
    const std::string& s) {
  return getSolution()(s);
}

IncreasingDecreasingStringSolution::IncreasingDecreasingStringSolution() {
  setMetaInfo({1370, "Increasing Decreasing String",
               "https://leetcode.com/problems/increasing-decreasing-string/"});
  registerStrategy({.name = "CountingSort",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(1)",
                    .tags = {"Hash Table", "String", "Counting"}},
                   sortStringImpl);
}

}  // namespace leetcode::problem_1370
