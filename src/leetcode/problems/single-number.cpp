#include "leetcode/problems/single-number.h"

namespace leetcode {
namespace problem_136 {

namespace {

int singleNumberImpl(std::vector<int>& nums) {
  int result = 0;
  for (int num : nums) {
    result ^= num;
  }
  return result;
}

}  // namespace

SingleNumberSolution::SingleNumberSolution() {
  setMetaInfo({136, "Single Number",
               "https://leetcode.com/problems/single-number/"});
  registerStrategy(
      {.name = "xor",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Bit Manipulation"},
       .notes =
           "XOR all elements; pairs cancel (a^a=0), leaving the single one."},
      singleNumberImpl);
}

int SingleNumberSolution::singleNumber(std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_136
}  // namespace leetcode
