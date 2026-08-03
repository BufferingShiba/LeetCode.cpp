#include "leetcode/problems/average-value-of-even-numbers-that-are-divisible-by-three.h"

namespace leetcode {
namespace problem_2455 {

namespace {

int averageValueImpl(std::vector<int>& nums) {
  long long sum = 0;
  int count = 0;
  for (int v : nums) {
    if (v % 6 == 0) {
      sum += v;
      ++count;
    }
  }
  return count == 0 ? 0 : static_cast<int>(sum / count);
}

}  // namespace

int AverageValueOfEvenNumbersThatAreDivisibleByThreeSolution::averageValue(
    std::vector<int>& nums) {
  return getSolution()(nums);
}

AverageValueOfEvenNumbersThatAreDivisibleByThreeSolution::
    AverageValueOfEvenNumbersThatAreDivisibleByThreeSolution() {
  setMetaInfo({2455,
               "Average Value of Even Numbers That Are Divisible by Three",
               "https://leetcode.com/problems/average-value-of-even-numbers-that-are-divisible-by-three/"});
  registerStrategy({.name = "linear-scan",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(1)",
                    .tags = {"Array", "Math"},
                    .notes = "Single pass: accumulate numbers divisible by 6 and floor-average."},
                   averageValueImpl);
}

}  // namespace problem_2455
}  // namespace leetcode
