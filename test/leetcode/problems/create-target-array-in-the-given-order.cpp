#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/create-target-array-in-the-given-order.h"

namespace leetcode {
namespace problem_1389 {
namespace {

class CreateTargetArrayInTheGivenOrderTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  CreateTargetArrayInTheGivenOrderSolution solution_;
};

TEST_P(CreateTargetArrayInTheGivenOrderTest, Example1) {
  std::vector<int> nums = {0, 1, 2, 3, 4};
  std::vector<int> index = {0, 1, 2, 2, 1};
  std::vector<int> expected = {0, 4, 1, 3, 2};
  EXPECT_EQ(solution_.createTargetArray(nums, index), expected);
}

TEST_P(CreateTargetArrayInTheGivenOrderTest, Example2) {
  std::vector<int> nums = {1, 2, 3, 4, 0};
  std::vector<int> index = {0, 1, 2, 3, 0};
  std::vector<int> expected = {0, 1, 2, 3, 4};
  EXPECT_EQ(solution_.createTargetArray(nums, index), expected);
}

TEST_P(CreateTargetArrayInTheGivenOrderTest, Example3) {
  std::vector<int> nums = {1};
  std::vector<int> index = {0};
  std::vector<int> expected = {1};
  EXPECT_EQ(solution_.createTargetArray(nums, index), expected);
}

TEST_P(CreateTargetArrayInTheGivenOrderTest, SelfAuthoredAllInsertAtZero) {
  std::vector<int> nums = {1, 2, 3};
  std::vector<int> index = {0, 0, 0};
  std::vector<int> expected = {3, 2, 1};
  EXPECT_EQ(solution_.createTargetArray(nums, index), expected);
}

INSTANTIATE_TEST_SUITE_P(
    CreateTargetArrayInTheGivenOrderTestSuite,
    CreateTargetArrayInTheGivenOrderTest,
    ::testing::ValuesIn(
        CreateTargetArrayInTheGivenOrderSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_1389
}  // namespace leetcode
