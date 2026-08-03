#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/find-closest-number-to-zero.h"

namespace leetcode {
namespace problem_2239 {
namespace {

class FindClosestNumberToZeroTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution_.setStrategy(GetParam());
  }

  FindClosestNumberToZeroSolution solution_;
};

TEST_P(FindClosestNumberToZeroTest, Example1) {
  std::vector<int> nums{-4, -2, 1, 4, 8};
  EXPECT_EQ(solution_.findClosestNumber(nums), 1);
}

TEST_P(FindClosestNumberToZeroTest, Example2) {
  std::vector<int> nums{2, -1, 1};
  EXPECT_EQ(solution_.findClosestNumber(nums), 1);
}

TEST_P(FindClosestNumberToZeroTest, SelfAuthoredSingleElement) {
  std::vector<int> nums{-5};
  EXPECT_EQ(solution_.findClosestNumber(nums), -5);
}

TEST_P(FindClosestNumberToZeroTest, SelfAuthoredZeroTiesPreferPositive) {
  std::vector<int> nums{-2, 2};
  EXPECT_EQ(solution_.findClosestNumber(nums), 2);
}

INSTANTIATE_TEST_SUITE_P(
    FindClosestNumberToZeroTestSuite,
    FindClosestNumberToZeroTest,
    ::testing::ValuesIn(
        FindClosestNumberToZeroSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_2239
}  // namespace leetcode
