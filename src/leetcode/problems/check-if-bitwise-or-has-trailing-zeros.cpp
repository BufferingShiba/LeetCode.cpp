#include "leetcode/problems/check-if-bitwise-or-has-trailing-zeros.h"

namespace leetcode {
namespace problem_2980 {

namespace {

bool hasTrailingZerosImpl(std::vector<int>& nums) {
  int evenCount = 0;
  for (int num : nums) {
    if (num % 2 == 0) {
      ++evenCount;
      if (evenCount >= 2) {
        return true;
      }
    }
  }
  return false;
}

}  // namespace

CheckIfBitwiseOrHasTrailingZerosSolution::CheckIfBitwiseOrHasTrailingZerosSolution() {
  setMetaInfo({.id = 2980,
               .title = "Check if Bitwise OR Has Trailing Zeros",
               .url = "https://leetcode.com/problems/check-if-bitwise-or-has-trailing-zeros/"});
  registerStrategy({.name = "even-count",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(1)",
                    .tags = {"Array", "Bit Manipulation"}},
                   hasTrailingZerosImpl);
}

bool CheckIfBitwiseOrHasTrailingZerosSolution::hasTrailingZeros(std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_2980
}  // namespace leetcode
