#include "leetcode/problems/construct-uniform-parity-array-i.h"

namespace leetcode::problem_3875 {
namespace {

// Observation: the answer is always true for any n >= 1.
//
// For any two distinct integers a, b:
//   - a - b is even when a and b share parity; odd otherwise.
// n == 1: the single element (odd or even) trivially forms a uniform array.
// n >= 2:
//   * If there are >= 2 odd numbers: every odd element can subtract another
//     odd to become even, while even elements stay even -> all-even array works.
//   * If there is >= 1 odd number: every even element can subtract that odd
//     to become odd, while odd elements stay odd -> all-odd array works.
//   * If all numbers are even: keep them unchanged -> all-even array works.
// In every scenario a valid uniform array can be constructed, so return true.
bool uniformArrayImpl(std::vector<int>& nums1) {
  (void)nums1;
  return true;
}

}  // namespace

ConstructUniformParityArrayISolution::ConstructUniformParityArrayISolution() {
  setMetaInfo({.id = 3875,
               .title = "Construct Uniform Parity Array I",
               .url = "https://leetcode.com/problems/construct-uniform-parity-array-i/"});
  registerStrategy(
      {.name = "ParityObservation",
       .expected = "Accepted",
       .time_complexity = "O(1)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Math"}},
      uniformArrayImpl);
}

bool ConstructUniformParityArrayISolution::uniformArray(std::vector<int>& nums1) {
  return getSolution()(nums1);
}

}  // namespace leetcode::problem_3875
