// Copyright (c) LeetCode.cpp Project.

#include <string>
#include <vector>

#include "leetcode/problems/check-whether-two-strings-are-almost-equivalent.h"

namespace leetcode {
namespace problem_2068 {

namespace {

bool checkAlmostEquivalentImpl(const std::string& word1,
                               const std::string& word2) {
  std::vector<int> freq(26, 0);
  for (char c : word1) {
    ++freq[c - 'a'];
  }
  for (char c : word2) {
    --freq[c - 'a'];
  }
  for (int diff : freq) {
    if (diff > 3 || diff < -3) {
      return false;
    }
  }
  return true;
}

}  // namespace

CheckWhetherTwoStringsAreAlmostEquivalentSolution::
    CheckWhetherTwoStringsAreAlmostEquivalentSolution() {
  setMetaInfo({.id = 2068,
               .title = "Check Whether Two Strings are Almost Equivalent",
               .url = "https://leetcode.com/problems/check-whether-two-strings-are-almost-equivalent/"});
  registerStrategy(
      {.name = "frequency-counting",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Hash Table", "String", "Counting"}},
      checkAlmostEquivalentImpl);
}

bool CheckWhetherTwoStringsAreAlmostEquivalentSolution::checkAlmostEquivalent(
    std::string word1, std::string word2) {
  return getSolution()(std::move(word1), std::move(word2));
}

}  // namespace problem_2068
}  // namespace leetcode
