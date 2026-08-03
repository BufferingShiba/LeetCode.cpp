#include <gtest/gtest.h>
#include <string>

#include "leetcode/problems/make-array-elements-equal-to-zero.h"

namespace leetcode::problem_3354 {

class MakeArrayElementsEqualToZeroTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MakeArrayElementsEqualToZeroSolution solution;
};

TEST_P(MakeArrayElementsEqualToZeroTest, Example1) {
  std::vector<int> nums = {1, 0, 2, 0, 3};
  EXPECT_EQ(solution.countValidSelections(nums), 2);
}

TEST_P(MakeArrayElementsEqualToZeroTest, Example2) {
  std::vector<int> nums = {2, 3, 4, 0, 4, 1, 0};
  EXPECT_EQ(solution.countValidSelections(nums), 0);
}

TEST_P(MakeArrayElementsEqualToZeroTest, SelfAuthoredSingleZero) {
  std::vector<int> nums = {0};
  // Only start at 0. Both directions immediately move out of range => zero array.
  EXPECT_EQ(solution.countValidSelections(nums), 2);
}

INSTANTIATE_TEST_SUITE_P(
    MakeArrayElementsEqualToZeroTestSuite, MakeArrayElementsEqualToZeroTest,
    ::testing::ValuesIn(MakeArrayElementsEqualToZeroSolution().getStrategyNames()));

}  // namespace leetcode::problem_3354
