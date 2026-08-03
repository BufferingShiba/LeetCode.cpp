#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/minimum-total-space-wasted-with-k-resizing-operations.h"

namespace leetcode {
namespace problem_1959 {

using leetcode::problem_1959::
    MinimumTotalSpaceWastedWithKResizingOperationsSolution;

class MinimumTotalSpaceWastedWithKResizingOperationsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  MinimumTotalSpaceWastedWithKResizingOperationsSolution solution_;
};

TEST_P(MinimumTotalSpaceWastedWithKResizingOperationsTest,
       Example1NoResize) {
  std::vector<int> nums = {10, 20};
  EXPECT_EQ(10, solution_.minSpaceWastedKResizing(nums, 0));
}

TEST_P(MinimumTotalSpaceWastedWithKResizingOperationsTest,
       Example2OneResize) {
  std::vector<int> nums = {10, 20, 30};
  EXPECT_EQ(10, solution_.minSpaceWastedKResizing(nums, 1));
}

TEST_P(MinimumTotalSpaceWastedWithKResizingOperationsTest,
       Example3TwoResizes) {
  std::vector<int> nums = {10, 20, 15, 30, 20};
  EXPECT_EQ(15, solution_.minSpaceWastedKResizing(nums, 2));
}

TEST_P(MinimumTotalSpaceWastedWithKResizingOperationsTest, SelfAuthoredSingleElement) {
  std::vector<int> nums = {7};
  EXPECT_EQ(0, solution_.minSpaceWastedKResizing(nums, 0));
}

INSTANTIATE_TEST_SUITE_P(
    MinimumTotalSpaceWastedWithKResizingOperationsTest,
    MinimumTotalSpaceWastedWithKResizingOperationsTest,
    ::testing::ValuesIn(
        MinimumTotalSpaceWastedWithKResizingOperationsSolution()
            .getStrategyNames()));

}  // namespace problem_1959
}  // namespace leetcode
