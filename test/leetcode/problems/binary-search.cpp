#include <gtest/gtest.h>

#include "leetcode/problems/binary-search.h"

namespace leetcode::problem_704 {
namespace {

class BinarySearchTest : public ::testing::TestWithParam<std::string> {
 protected:
  BinarySearchSolution solution;
  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(BinarySearchTest, Example1) {
  std::vector<int> nums = {-1, 0, 3, 5, 9, 12};
  EXPECT_EQ(solution.search(nums, 9), 4);
}

TEST_P(BinarySearchTest, Example2) {
  std::vector<int> nums = {-1, 0, 3, 5, 9, 12};
  EXPECT_EQ(solution.search(nums, 2), -1);
}

TEST_P(BinarySearchTest, SelfAuthoredSingleElementFound) {
  std::vector<int> nums = {5};
  EXPECT_EQ(solution.search(nums, 5), 0);
}

TEST_P(BinarySearchTest, SelfAuthoredSingleElementNotFound) {
  std::vector<int> nums = {5};
  EXPECT_EQ(solution.search(nums, 3), -1);
}

INSTANTIATE_TEST_SUITE_P(
    BinarySearchStrategies, BinarySearchTest,
    ::testing::ValuesIn(BinarySearchSolution().getStrategyNames()));

}  // namespace
}  // namespace leetcode::problem_704
