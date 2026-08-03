#include <gtest/gtest.h>

#include "leetcode/problems/find-the-minimum-possible-sum-of-a-beautiful-array.h"

namespace leetcode::problem_2834 {
namespace {

class FindTheMinimumPossibleSumOfABeautifulArrayTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  FindTheMinimumPossibleSumOfABeautifulArraySolution solution_;
};

TEST_P(FindTheMinimumPossibleSumOfABeautifulArrayTest, Example1) {
  EXPECT_EQ(solution_.minimumPossibleSum(2, 3), 4);
}

TEST_P(FindTheMinimumPossibleSumOfABeautifulArrayTest, Example2) {
  EXPECT_EQ(solution_.minimumPossibleSum(3, 3), 8);
}

TEST_P(FindTheMinimumPossibleSumOfABeautifulArrayTest, Example3) {
  EXPECT_EQ(solution_.minimumPossibleSum(1, 1), 1);
}

TEST_P(FindTheMinimumPossibleSumOfABeautifulArrayTest, SelfAuthored_AllFromHalfRange) {
  // target=10, m=5, n=3 <= m: pick 1,2,3 -> sum=6
  EXPECT_EQ(solution_.minimumPossibleSum(3, 10), 6);
}

TEST_P(FindTheMinimumPossibleSumOfABeautifulArrayTest, SelfAuthored_NeedBeyondTarget) {
  // target=5, m=2 (pick 1,2), n=4: extra 5,6 -> sum=1+2+5+6=14
  EXPECT_EQ(solution_.minimumPossibleSum(4, 5), 14);
}

TEST_P(FindTheMinimumPossibleSumOfABeautifulArrayTest, SelfAuthored_TargetOne) {
  // target=1, m=0: all numbers from target=1: 1,2,3 -> sum=6
  EXPECT_EQ(solution_.minimumPossibleSum(3, 1), 6);
}

TEST_P(FindTheMinimumPossibleSumOfABeautifulArrayTest, SelfAuthored_LargeN) {
  // Just verify no overflow and returns a positive value.
  int result = solution_.minimumPossibleSum(1'000'000'000, 1'000'000'000);
  EXPECT_GT(result, 0);
  EXPECT_LT(result, 1'000'000'007);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    FindTheMinimumPossibleSumOfABeautifulArrayTest,
    testing::ValuesIn(
        FindTheMinimumPossibleSumOfABeautifulArraySolution().getStrategyNames()));

}  // namespace
}  // namespace leetcode::problem_2834
