#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/maximize-expression-of-three-elements.h"

namespace leetcode {
namespace problem_3745 {
namespace {

class MaximizeExpressionOfThreeElementsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution_.setStrategy(GetParam());
  }

  MaximizeExpressionOfThreeElementsSolution solution_;
};

TEST_P(MaximizeExpressionOfThreeElementsTest, Example1) {
  std::vector<int> nums{1, 4, 2, 5};
  EXPECT_EQ(8, solution_.maximizeExpressionOfThree(nums));
}

TEST_P(MaximizeExpressionOfThreeElementsTest, Example2) {
  std::vector<int> nums{-2, 0, 5, -2, 4};
  EXPECT_EQ(11, solution_.maximizeExpressionOfThree(nums));
}

TEST_P(MaximizeExpressionOfThreeElementsTest, SelfAuthoredAllSameValues) {
  std::vector<int> nums{5, 5, 5};
  EXPECT_EQ(5, solution_.maximizeExpressionOfThree(nums));
}

TEST_P(MaximizeExpressionOfThreeElementsTest, SelfAuthoredNegativeOnly) {
  std::vector<int> nums{-5, -3, -1};
  EXPECT_EQ(1, solution_.maximizeExpressionOfThree(nums));
}

INSTANTIATE_TEST_SUITE_P(
    MaximizeExpressionOfThreeElementsTestCases,
    MaximizeExpressionOfThreeElementsTest,
    ::testing::ValuesIn(
        MaximizeExpressionOfThreeElementsSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_3745
}  // namespace leetcode
