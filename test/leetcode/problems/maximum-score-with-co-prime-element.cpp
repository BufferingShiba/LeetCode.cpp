#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/maximum-score-with-co-prime-element.h"

namespace leetcode {
namespace problem_3953 {

class MaximumScoreWithCoPrimeElementTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MaximumScoreWithCoPrimeElementSolution solution;
};

TEST_P(MaximumScoreWithCoPrimeElementTest, Example1) {
  std::vector<int> nums = {3, 4, 6};
  EXPECT_EQ(4, solution.maxScore(nums, 5));
}

TEST_P(MaximumScoreWithCoPrimeElementTest, Example2) {
  std::vector<int> nums = {1, 2, 3};
  EXPECT_EQ(3, solution.maxScore(nums, 4));
}

TEST_P(MaximumScoreWithCoPrimeElementTest, Example3) {
  std::vector<int> nums = {2, 2};
  EXPECT_EQ(1, solution.maxScore(nums, 1));
}

TEST_P(MaximumScoreWithCoPrimeElementTest, RepeatedConflictCanScoreZero) {
  std::vector<int> nums = {2, 2, 2};
  EXPECT_EQ(0, solution.maxScore(nums, 1));
}

INSTANTIATE_TEST_SUITE_P(
    MaximumScoreWithCoPrimeElementTestSuite,
    MaximumScoreWithCoPrimeElementTest,
    ::testing::ValuesIn(
        MaximumScoreWithCoPrimeElementSolution().getStrategyNames()));

}  // namespace problem_3953
}  // namespace leetcode
