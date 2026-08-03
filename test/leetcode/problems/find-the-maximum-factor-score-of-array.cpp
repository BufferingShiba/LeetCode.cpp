#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/find-the-maximum-factor-score-of-array.h"

namespace leetcode::problem_3334 {

namespace {

long long expectedForExample1() {
  return 64;
}

}  // namespace

class FindTheMaximumFactorScoreOfArrayTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution_.setStrategy(GetParam());
  }

  FindTheMaximumFactorScoreOfArraySolution solution_;
};

TEST_P(FindTheMaximumFactorScoreOfArrayTest, Example1) {
  std::vector<int> nums{2, 4, 8, 16};
  EXPECT_EQ(solution_.maxScore(nums), 64);
}

TEST_P(FindTheMaximumFactorScoreOfArrayTest, Example2) {
  std::vector<int> nums{1, 2, 3, 4, 5};
  EXPECT_EQ(solution_.maxScore(nums), 60);
}

TEST_P(FindTheMaximumFactorScoreOfArrayTest, Example3) {
  std::vector<int> nums{3};
  EXPECT_EQ(solution_.maxScore(nums), 9);
}

INSTANTIATE_TEST_SUITE_P(
    FindTheMaximumFactorScoreOfArrayTests,
    FindTheMaximumFactorScoreOfArrayTest,
    ::testing::ValuesIn(FindTheMaximumFactorScoreOfArraySolution().getStrategyNames()));

}  // namespace leetcode::problem_3334
