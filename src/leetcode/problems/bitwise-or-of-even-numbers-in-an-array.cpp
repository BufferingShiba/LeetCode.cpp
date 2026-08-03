#include "leetcode/problems/bitwise-or-of-even-numbers-in-an-array.h"

namespace leetcode {
namespace problem_3688 {

namespace {

int evenNumberBitwiseORsImpl(std::vector<int>& nums) {
  int result = 0;
  for (int num : nums) {
    if (num % 2 == 0) {
      result |= num;
    }
  }
  return result;
}

}  // namespace

BitwiseOrOfEvenNumbersInAnArraySolution::BitwiseOrOfEvenNumbersInAnArraySolution() {
  setMetaInfo({3688, "Bitwise OR of Even Numbers in an Array",
               "https://leetcode.com/problems/bitwise-or-of-even-numbers-in-an-array/"});
  registerStrategy(
      {"IterativeSimulation", "Accepted", "O(n)", "O(1)",
       {"Array", "Bit Manipulation", "Simulation"}},
      evenNumberBitwiseORsImpl);
}

int BitwiseOrOfEvenNumbersInAnArraySolution::evenNumberBitwiseORs(
    std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_3688
}  // namespace leetcode
