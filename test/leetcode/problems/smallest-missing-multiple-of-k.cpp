#include <gtest/gtest.h>

#include "leetcode/problems/smallest-missing-multiple-of-k.h"

namespace leetcode {
namespace problem_3718 {
namespace {

class SmallestMissingMultipleOfKTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  SmallestMissingMultipleOfKSolution solution_;
};

TEST_P(SmallestMissingMultipleOfKTest, Example1) {
  std::vector<int> nums{8, 2, 3, 4, 6};
  int k = 2;
  EXPECT_EQ(solution_.missingMultiple(nums, k), 10);
}

TEST_P(SmallestMissingMultipleOfKTest, Example2) {
  std::vector<int> nums{1, 4, 7, 10, 15};
  int k = 5;
  EXPECT_EQ(solution_.missingMultiple(nums, k), 5);
}

TEST_P(SmallestMissingMultipleOfKTest, SelfAuthoredAllPresent) {
  std::vector<int> nums{2, 4, 6, 8, 10};
  int k = 2;
  EXPECT_EQ(solution_.missingMultiple(nums, k), 12);
}

TEST_P(SmallestMissingMultipleOfKTest, SelfAuthoredKEqualsOne) {
  std::vector<int> nums{1, 2, 3, 4, 5};
  int k = 1;
  EXPECT_EQ(solution_.missingMultiple(nums, k), 6);
}

INSTANTIATE_TEST_SUITE_P(
    SmallestMissingMultipleOfKTestCases, SmallestMissingMultipleOfKTest,
    ::testing::ValuesIn(SmallestMissingMultipleOfKSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_3718
}  // namespace leetcode
