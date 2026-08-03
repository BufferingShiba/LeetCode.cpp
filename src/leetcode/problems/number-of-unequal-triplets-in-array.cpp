#include "leetcode/problems/number-of-unequal-triplets-in-array.h"

namespace leetcode {
namespace problem_2475 {

namespace {

int unequalTripletsBruteForce(std::vector<int>& nums) {
  const int n = static_cast<int>(nums.size());
  int count = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      for (int k = j + 1; k < n; ++k) {
        if (nums[i] != nums[j] && nums[i] != nums[k] && nums[j] != nums[k]) {
          ++count;
        }
      }
    }
  }
  return count;
}

}  // namespace

NumberOfUnequalTripletsInArraySolution::NumberOfUnequalTripletsInArraySolution() {
  setMetaInfo({.id = 2475,
               .title = "Number of Unequal Triplets in Array",
               .url = "https://leetcode.com/problems/number-of-unequal-triplets-in-array/"});
  registerStrategy(
      {.name = "BruteForce",
       .expected = "Accepted",
       .time_complexity = "O(n^3)",
       .space_complexity = "O(1)",
       .tags = {"Array"},
       .notes = "Enumerate all i<j<k and check pairwise distinct."},
      unequalTripletsBruteForce);
}

int NumberOfUnequalTripletsInArraySolution::unequalTriplets(std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_2475
}  // namespace leetcode
