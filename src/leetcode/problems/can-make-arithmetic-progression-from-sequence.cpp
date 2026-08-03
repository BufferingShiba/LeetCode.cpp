#include "leetcode/problems/can-make-arithmetic-progression-from-sequence.h"

#include <algorithm>

namespace leetcode::problem_1502 {

namespace {

bool canMakeArithmeticProgressionImpl(std::vector<int>& arr) {
  std::sort(arr.begin(), arr.end());
  const int diff = arr[1] - arr[0];
  for (size_t i = 1; i < arr.size() - 1; ++i) {
    if (arr[i + 1] - arr[i] != diff) {
      return false;
    }
  }
  return true;
}

}  // namespace

CanMakeArithmeticProgressionFromSequenceSolution::
    CanMakeArithmeticProgressionFromSequenceSolution() {
  setMetaInfo({.id = 1502,
               .title = "Can Make Arithmetic Progression From Sequence",
               .url = "https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/"});
  registerStrategy(
      {.name = "sort_and_check",
       .expected = "Accepted",
       .time_complexity = "O(n log n)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Sorting"}},
      canMakeArithmeticProgressionImpl);
}

bool CanMakeArithmeticProgressionFromSequenceSolution::
    canMakeArithmeticProgression(std::vector<int>& arr) {
  return getSolution()(arr);
}

}  // namespace leetcode::problem_1502
