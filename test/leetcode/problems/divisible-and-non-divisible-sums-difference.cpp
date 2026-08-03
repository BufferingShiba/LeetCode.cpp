#include "leetcode/problems/divisible-and-non-divisible-sums-difference.h"

#include <gtest/gtest.h>

#include <string>

using leetcode::problem_2894::DivisibleAndNonDivisibleSumsDifferenceSolution;

namespace leetcode {
namespace problem_2894 {
namespace test {

class DivisibleAndNonDivisibleSumsDifferenceTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  DivisibleAndNonDivisibleSumsDifferenceSolution solution_;
};

TEST_P(DivisibleAndNonDivisibleSumsDifferenceTest, Example1) {
  EXPECT_EQ(solution_.differenceOfSums(10, 3), 19);
}

TEST_P(DivisibleAndNonDivisibleSumsDifferenceTest, Example2) {
  EXPECT_EQ(solution_.differenceOfSums(5, 6), 15);
}

TEST_P(DivisibleAndNonDivisibleSumsDifferenceTest, Example3) {
  EXPECT_EQ(solution_.differenceOfSums(5, 1), -15);
}

TEST_P(DivisibleAndNonDivisibleSumsDifferenceTest, SelfAuthoredBoundaryN1) {
  EXPECT_EQ(solution_.differenceOfSums(1, 1), -1);
}

TEST_P(DivisibleAndNonDivisibleSumsDifferenceTest, SelfAuthoredBoundaryN1M2) {
  EXPECT_EQ(solution_.differenceOfSums(1, 2), 1);
}

INSTANTIATE_TEST_SUITE_P(
    DivisibleAndNonDivisibleSumsDifferenceTestParameters,
    DivisibleAndNonDivisibleSumsDifferenceTest,
    ::testing::ValuesIn(
        DivisibleAndNonDivisibleSumsDifferenceSolution().getStrategyNames()));

}  // namespace test
}  // namespace problem_2894
}  // namespace leetcode
