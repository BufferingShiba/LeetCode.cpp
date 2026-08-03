#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/minimum-swaps-to-move-zeros-to-end.h"

namespace leetcode {
namespace problem_3936 {
namespace {

class MinimumSwapsToMoveZerosToEndTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  MinimumSwapsToMoveZerosToEndSolution solution;

  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(MinimumSwapsToMoveZerosToEndTest, Example1) {
  std::vector<int> nums = {0, 1, 0, 3, 12};
  EXPECT_EQ(2, solution.minimumSwaps(nums));
}

TEST_P(MinimumSwapsToMoveZerosToEndTest, Example2) {
  std::vector<int> nums = {0, 1, 0, 2};
  EXPECT_EQ(1, solution.minimumSwaps(nums));
}

TEST_P(MinimumSwapsToMoveZerosToEndTest, Example3) {
  std::vector<int> nums = {1, 2, 0};
  EXPECT_EQ(0, solution.minimumSwaps(nums));
}

TEST_P(MinimumSwapsToMoveZerosToEndTest, SelfAuthoredNoZeros) {
  std::vector<int> nums = {1, 2, 3};
  EXPECT_EQ(0, solution.minimumSwaps(nums));
}

TEST_P(MinimumSwapsToMoveZerosToEndTest, SelfAuthoredAllZeros) {
  std::vector<int> nums = {0, 0, 0};
  EXPECT_EQ(0, solution.minimumSwaps(nums));
}

TEST_P(MinimumSwapsToMoveZerosToEndTest, SelfAuthoredSingleZeroAtFront) {
  std::vector<int> nums = {0, 0, 1, 0};
  EXPECT_EQ(1, solution.minimumSwaps(nums));
}

INSTANTIATE_TEST_SUITE_P(
    MinimumSwapsToMoveZerosToEndTest, MinimumSwapsToMoveZerosToEndTest,
    ::testing::ValuesIn(MinimumSwapsToMoveZerosToEndSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_3936
}  // namespace leetcode
