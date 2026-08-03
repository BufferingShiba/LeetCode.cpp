#include <gtest/gtest.h>
#include "leetcode/problems/arithmetic-slices.h"
#include <string>
#include <vector>

namespace leetcode {
namespace problem_413 {

class ArithmeticSlicesTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution.setStrategy(GetParam());
  }

  ArithmeticSlicesSolution solution;
};

TEST_P(ArithmeticSlicesTest, Example1) {
  std::vector<int> nums = {1, 2, 3, 4};
  EXPECT_EQ(3, solution.numberOfArithmeticSlices(nums));
}

TEST_P(ArithmeticSlicesTest, Example2) {
  std::vector<int> nums = {1};
  EXPECT_EQ(0, solution.numberOfArithmeticSlices(nums));
}

TEST_P(ArithmeticSlicesTest, SelfAuthoredTwoElements) {
  std::vector<int> nums = {1, 2};
  EXPECT_EQ(0, solution.numberOfArithmeticSlices(nums));
}

TEST_P(ArithmeticSlicesTest, SelfAuthoredSingleTriple) {
  std::vector<int> nums = {1, 2, 3};
  EXPECT_EQ(1, solution.numberOfArithmeticSlices(nums));
}

TEST_P(ArithmeticSlicesTest, SelfAuthoredNegativeAndEqualDiffs) {
  std::vector<int> nums = {3, -1, -5, -9};
  EXPECT_EQ(3, solution.numberOfArithmeticSlices(nums));
}

TEST_P(ArithmeticSlicesTest, SelfAuthoredMultipleRuns) {
  std::vector<int> nums = {1, 2, 3, 8, 9, 10};
  // [1,2,3], [8,9,10]
  EXPECT_EQ(2, solution.numberOfArithmeticSlices(nums));
}

INSTANTIATE_TEST_SUITE_P(ArithmeticSlicesTestSuite, ArithmeticSlicesTest,
                         ::testing::ValuesIn(ArithmeticSlicesSolution().getStrategyNames()));

}  // namespace problem_413
}  // namespace leetcode
