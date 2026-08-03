#include <gtest/gtest.h>
#include <string>
#include <vector>

#include "leetcode/problems/average-value-of-even-numbers-that-are-divisible-by-three.h"

namespace leetcode {
namespace problem_2455 {

class AverageValueOfEvenNumbersThatAreDivisibleByThreeTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  AverageValueOfEvenNumbersThatAreDivisibleByThreeSolution solution;
};

TEST_P(AverageValueOfEvenNumbersThatAreDivisibleByThreeTest, Example1) {
  std::vector<int> nums = {1, 3, 6, 10, 12, 15};
  EXPECT_EQ(9, solution.averageValue(nums));
}

TEST_P(AverageValueOfEvenNumbersThatAreDivisibleByThreeTest, Example2) {
  std::vector<int> nums = {1, 2, 4, 7, 10};
  EXPECT_EQ(0, solution.averageValue(nums));
}

TEST_P(AverageValueOfEvenNumbersThatAreDivisibleByThreeTest, SelfAuthoredSingleElement) {
  std::vector<int> nums = {18};
  EXPECT_EQ(18, solution.averageValue(nums));
}

TEST_P(AverageValueOfEvenNumbersThatAreDivisibleByThreeTest, SelfAuthoredFloorRounding) {
  std::vector<int> nums = {6, 6, 12};
  EXPECT_EQ(8, solution.averageValue(nums));  // (6+6+12)/3 = 8
}

INSTANTIATE_TEST_SUITE_P(
    AverageValueOfEvenNumbersThatAreDivisibleByThreeTestInstance,
    AverageValueOfEvenNumbersThatAreDivisibleByThreeTest,
    ::testing::ValuesIn(
        AverageValueOfEvenNumbersThatAreDivisibleByThreeSolution()
            .getStrategyNames()));

}  // namespace problem_2455
}  // namespace leetcode
