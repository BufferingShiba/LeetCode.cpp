#include "leetcode/problems/number-of-different-integers-in-a-string.h"

#include <string>
#include <unordered_set>

namespace leetcode {
namespace problem_1805 {

namespace {

int numDifferentIntegersImpl(const std::string& word) {
  std::unordered_set<std::string> seen;
  const int n = static_cast<int>(word.size());
  int i = 0;
  while (i < n) {
    if (word[i] < '0' || word[i] > '9') {
      ++i;
      continue;
    }
    // Collect a run of digits.
    int j = i;
    while (j < n && word[j] >= '0' && word[j] <= '9') {
      ++j;
    }
    // Skip leading zeros.
    int k = i;
    while (k < j && word[k] == '0') {
      ++k;
    }
    if (k == j) {
      seen.insert("0");
    } else {
      seen.insert(word.substr(k, j - k));
    }
    i = j;
  }
  return static_cast<int>(seen.size());
}

}  // namespace

NumberOfDifferentIntegersInAStringSolution::
    NumberOfDifferentIntegersInAStringSolution() {
  setMetaInfo({.id = 1805,
               .title = "Number of Different Integers in a String",
               .url = "https://leetcode.com/problems/number-of-different-integers-in-a-string/"});
  registerStrategy(
      {.name = "HashSetScan",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(n)",
       .tags = {"Hash Table", "String"}},
      numDifferentIntegersImpl);
}

int NumberOfDifferentIntegersInAStringSolution::numDifferentIntegers(
    std::string word) {
  return getSolution()(std::move(word));
}

}  // namespace problem_1805
}  // namespace leetcode
