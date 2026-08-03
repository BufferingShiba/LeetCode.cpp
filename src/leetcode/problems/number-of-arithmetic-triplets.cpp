#include "leetcode/problems/number-of-arithmetic-triplets.h"

#include <unordered_set>

namespace leetcode::problem_2367 {

namespace {

int arithmeticTripletsImpl(std::vector<int>& nums, int diff) {
  std::unordered_set<int> seen;
  for (int v : nums) {
    seen.insert(v);
  }
  int count = 0;
  for (int v : nums) {
    if (seen.count(v + diff) > 0 && seen.count(v + 2 * diff) > 0) {
      ++count;
    }
  }
  return count;
}

}  // namespace

NumberOfArithmeticTripletsSolution::NumberOfArithmeticTripletsSolution() {
  setMetaInfo({.id = 2367,
               .title = "Number of Arithmetic Triplets",
               .url = "https://leetcode.com/problems/number-of-arithmetic-triplets/"});

  registerStrategy(
      {.name = "HashSet",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(n)",
       .tags = {"Array", "Hash Table"}},
      arithmeticTripletsImpl);
}

int NumberOfArithmeticTripletsSolution::arithmeticTriplets(std::vector<int>& nums,
                                                            int diff) {
  return getSolution()(nums, diff);
}

}  // namespace leetcode::problem_2367
