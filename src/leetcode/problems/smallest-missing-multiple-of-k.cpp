#include "leetcode/problems/smallest-missing-multiple-of-k.h"

#include <unordered_set>

namespace leetcode {
namespace problem_3718 {

namespace {

int missingMultipleImpl(std::vector<int>& nums, int k) {
  std::unordered_set<int> present(nums.begin(), nums.end());
  int multiple = k;
  while (present.count(multiple) > 0) {
    multiple += k;
  }
  return multiple;
}

}  // namespace

SmallestMissingMultipleOfKSolution::SmallestMissingMultipleOfKSolution() {
  setMetaInfo({.id = 3718,
               .title = "Smallest Missing Multiple of K",
               .url = "https://leetcode.com/problems/smallest-missing-multiple-of-k/"});

  registerStrategy({.name = "HashSetIterateMultiples",
                    .expected = "Accepted",
                    .time_complexity = "O(n + m/k)",
                    .space_complexity = "O(n)",
                    .tags = {"Array", "Hash Table"}},
                   missingMultipleImpl);
}

int SmallestMissingMultipleOfKSolution::missingMultiple(std::vector<int>& nums, int k) {
  return getSolution()(nums, k);
}

}  // namespace problem_3718
}  // namespace leetcode
