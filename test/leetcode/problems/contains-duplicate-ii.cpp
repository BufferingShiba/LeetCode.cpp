#include <gtest/gtest.h>

#include <vector>

#include "leetcode/problems/contains-duplicate-ii.h"

namespace leetcode::problem_219 {

class ContainsDuplicateIiTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  ContainsDuplicateIiSolution solution;
};

TEST_P(ContainsDuplicateIiTest, Example1) {
  std::vector<int> nums = {1, 2, 3, 1};
  EXPECT_TRUE(solution.containsNearbyDuplicate(nums, 3));
}

TEST_P(ContainsDuplicateIiTest, Example2) {
  std::vector<int> nums = {1, 0, 1, 1};
  EXPECT_TRUE(solution.containsNearbyDuplicate(nums, 1));
}

TEST_P(ContainsDuplicateIiTest, Example3) {
  std::vector<int> nums = {1, 2, 3, 1, 2, 3};
  EXPECT_FALSE(solution.containsNearbyDuplicate(nums, 2));
}

INSTANTIATE_TEST_SUITE_P(
    ContainsDuplicateIiTestSuite, ContainsDuplicateIiTest,
    ::testing::ValuesIn(ContainsDuplicateIiSolution().getStrategyNames()));

}  // namespace leetcode::problem_219
