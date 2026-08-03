#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/minimum-operations-to-collect-elements.h"

namespace leetcode {
namespace problem_2869 {
namespace {

class MinimumOperationsToCollectElementsTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  MinimumOperationsToCollectElementsSolution solution_;
};

TEST_P(MinimumOperationsToCollectElementsTest, Example1) {
  std::vector<int> nums{3, 1, 5, 4, 2};
  EXPECT_EQ(solution_.minOperations(nums, 2), 4);
}

TEST_P(MinimumOperationsToCollectElementsTest, Example2) {
  std::vector<int> nums{3, 1, 5, 4, 2};
  EXPECT_EQ(solution_.minOperations(nums, 5), 5);
}

TEST_P(MinimumOperationsToCollectElementsTest, Example3) {
  std::vector<int> nums{3, 2, 5, 3, 1};
  EXPECT_EQ(solution_.minOperations(nums, 3), 4);
}

TEST_P(MinimumOperationsToCollectElementsTest, SingleElement) {
  std::vector<int> nums{1};
  EXPECT_EQ(solution_.minOperations(nums, 1), 1);
}

TEST_P(MinimumOperationsToCollectElementsTest, KEqualsOne) {
  std::vector<int> nums{4, 3, 1, 2};
  EXPECT_EQ(solution_.minOperations(nums, 1), 2);
}

TEST_P(MinimumOperationsToCollectElementsTest, CollectFromEnd) {
  std::vector<int> nums{1, 2, 3, 4, 5};
  EXPECT_EQ(solution_.minOperations(nums, 3), 5);
}

INSTANTIATE_TEST_SUITE_P(
    MinimumOperationsToCollectElementsTestSuite, MinimumOperationsToCollectElementsTest,
    ::testing::ValuesIn(MinimumOperationsToCollectElementsSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_2869
}  // namespace leetcode
