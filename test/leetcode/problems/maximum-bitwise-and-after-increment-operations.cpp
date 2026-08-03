#include "leetcode/problems/maximum-bitwise-and-after-increment-operations.h"

#include <gtest/gtest.h>

#include <string>
#include <vector>

namespace leetcode {
namespace problem_3806 {

class MaximumBitwiseAndAfterIncrementOperationsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MaximumBitwiseAndAfterIncrementOperationsSolution solution;
};

TEST_P(MaximumBitwiseAndAfterIncrementOperationsTest, Example1) {
  std::vector<int> nums = {3, 1, 2};
  EXPECT_EQ(solution.maximumAND(nums, 8, 2), 6);
}

TEST_P(MaximumBitwiseAndAfterIncrementOperationsTest, Example2) {
  std::vector<int> nums = {1, 2, 8, 4};
  EXPECT_EQ(solution.maximumAND(nums, 7, 3), 4);
}

TEST_P(MaximumBitwiseAndAfterIncrementOperationsTest, Example3) {
  std::vector<int> nums = {1, 1};
  EXPECT_EQ(solution.maximumAND(nums, 3, 2), 2);
}

TEST_P(MaximumBitwiseAndAfterIncrementOperationsTest, SingleElement) {
  std::vector<int> nums = {3};
  EXPECT_EQ(solution.maximumAND(nums, 2, 1), 5);
}

TEST_P(MaximumBitwiseAndAfterIncrementOperationsTest, RaiseBothToSix) {
  // Both 4 can be incremented to 6 (cost 2 each), AND = 6.
  std::vector<int> nums = {4, 4};
  EXPECT_EQ(solution.maximumAND(nums, 5, 2), 6);
}

TEST_P(MaximumBitwiseAndAfterIncrementOperationsTest, RaiseBothToSeven) {
  // Both 4 can be incremented to 7 (cost 3 each, total 6 <= 7), AND = 7.
  std::vector<int> nums = {4, 4};
  EXPECT_EQ(solution.maximumAND(nums, 7, 2), 7);
}

INSTANTIATE_TEST_SUITE_P(
    MaximumBitwiseAndAfterIncrementOperationsTestSuite,
    MaximumBitwiseAndAfterIncrementOperationsTest,
    ::testing::ValuesIn(
        MaximumBitwiseAndAfterIncrementOperationsSolution().getStrategyNames()));

}  // namespace problem_3806
}  // namespace leetcode
