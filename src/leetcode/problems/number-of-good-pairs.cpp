#include "leetcode/problems/number-of-good-pairs.h"

#include <unordered_map>

namespace leetcode::problem_1512 {

namespace {

int numIdenticalPairsImpl(std::vector<int>& nums) {
  std::unordered_map<int, int> count;
  for (int num : nums) {
    ++count[num];
  }
  int result = 0;
  for (const auto& entry : count) {
    int cnt = entry.second;
    result += cnt * (cnt - 1) / 2;
  }
  return result;
}

}  // namespace

NumberOfGoodPairsSolution::NumberOfGoodPairsSolution() {
  setMetaInfo({.id = 1512,
               .title = "Number of Good Pairs",
               .url = "https://leetcode.com/problems/number-of-good-pairs/"});
  registerStrategy({.name =
                        "Counting",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(1)",
                    .tags = {"Array", "Hash Table", "Math", "Counting"}},
                   numIdenticalPairsImpl);
}

int NumberOfGoodPairsSolution::numIdenticalPairs(std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace leetcode::problem_1512
