#include "leetcode/problems/permutation-difference-between-two-strings.h"

#include <cstdlib>
#include <unordered_map>

namespace leetcode::problem_3146 {

namespace {

int findPermutationDifferenceImpl(std::string s, std::string t) {
  std::unordered_map<char, int> pos;
  for (int i = 0; i < static_cast<int>(s.size()); ++i) {
    pos[s[i]] = i;
  }
  int sum = 0;
  for (int i = 0; i < static_cast<int>(t.size()); ++i) {
    sum += std::abs(pos[t[i]] - i);
  }
  return sum;
}

}  // namespace

PermutationDifferenceBetweenTwoStringsSolution::
    PermutationDifferenceBetweenTwoStringsSolution() {
  setMetaInfo({.id = 3146,
               .title = "Permutation Difference between Two Strings",
               .url = "https://leetcode.com/problems/permutation-difference-between-two-strings/"});
  registerStrategy({.name = "hash-map-index",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(1)",
                    .tags = {"Hash Table", "String"}},
                   findPermutationDifferenceImpl);
}

int PermutationDifferenceBetweenTwoStringsSolution::findPermutationDifference(
    std::string s, std::string t) {
  return getSolution()(std::move(s), std::move(t));
}

}  // namespace leetcode::problem_3146
