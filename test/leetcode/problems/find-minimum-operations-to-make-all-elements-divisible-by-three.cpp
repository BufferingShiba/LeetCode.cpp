#include <gtest/gtest.h>

#include "leetcode/problems/find-minimum-operations-to-make-all-elements-divisible-by-three.h"

namespace leetcode::problem_3190 {

class FindMinimumOperationsToMakeAllElementsDivisibleByThreeTest
    : public testing::TestWithParam<std::string> {
 protected:
  FindMinimumOperationsToMakeAllElementsDivisibleByThreeSolution solution;

  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(FindMinimumOperationsToMakeAllElementsDivisibleByThreeTest, Examples) {
  {
    std::vector<int> nums = {1, 2, 3, 4};
    EXPECT_EQ(solution.minimumOperations(nums), 3);
  }
  {
    std::vector<int> nums = {3, 6, 9};
    EXPECT_EQ(solution.minimumOperations(nums), 0);
  }
}

TEST_P(FindMinimumOperationsToMakeAllElementsDivisibleByThreeTest,
       SelfAuthored) {
  // Single element
  {
    std::vector<int> nums = {1};
    EXPECT_EQ(solution.minimumOperations(nums), 1);
  }
  {
    std::vector<int> nums = {3};
    EXPECT_EQ(solution.minimumOperations(nums), 0);
  }
  // Mixed
  {
    std::vector<int> nums = {2, 4, 5, 7};
    // 2%3=2 →1, 4%3=1 →1, 5%3=2 →1, 7%3=1 →1
    EXPECT_EQ(solution.minimumOperations(nums), 4);
  }
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    FindMinimumOperationsToMakeAllElementsDivisibleByThreeTest,
    testing::ValuesIn(
        FindMinimumOperationsToMakeAllElementsDivisibleByThreeSolution()
            .getStrategyNames()));

}  // namespace leetcode::problem_3190
