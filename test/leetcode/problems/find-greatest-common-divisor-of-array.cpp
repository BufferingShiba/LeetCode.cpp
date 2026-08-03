#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/find-greatest-common-divisor-of-array.h"

namespace leetcode {
namespace problem_1979 {
namespace {

using FindGreatestCommonDivisorOfArrayTest =
    ::testing::TestWithParam<std::string>;

}  // namespace

TEST_P(FindGreatestCommonDivisorOfArrayTest, Example1) {
  FindGreatestCommonDivisorOfArraySolution solution;
  solution.setStrategy(GetParam());
  std::vector<int> nums = {2, 5, 6, 9, 10};
  EXPECT_EQ(solution.findGCD(nums), 2);
}

TEST_P(FindGreatestCommonDivisorOfArrayTest, Example2) {
  FindGreatestCommonDivisorOfArraySolution solution;
  solution.setStrategy(GetParam());
  std::vector<int> nums = {7, 5, 6, 8, 3};
  EXPECT_EQ(solution.findGCD(nums), 1);
}

TEST_P(FindGreatestCommonDivisorOfArrayTest, Example3) {
  FindGreatestCommonDivisorOfArraySolution solution;
  solution.setStrategy(GetParam());
  std::vector<int> nums = {3, 3};
  EXPECT_EQ(solution.findGCD(nums), 3);
}

TEST_P(FindGreatestCommonDivisorOfArrayTest, SelfAuthored) {
  FindGreatestCommonDivisorOfArraySolution solution;
  solution.setStrategy(GetParam());

  {
    std::vector<int> nums = {12, 8, 16};
    EXPECT_EQ(solution.findGCD(nums), 8);  // min=8, max=16, gcd=8
  }
  {
    std::vector<int> nums = {1000, 1};
    EXPECT_EQ(solution.findGCD(nums), 1);  // min=1, max=1000, gcd=1
  }
  {
    std::vector<int> nums = {6, 9};
    EXPECT_EQ(solution.findGCD(nums), 3);  // min=6, max=9, gcd=3
  }
}

INSTANTIATE_TEST_SUITE_P(
    FindGreatestCommonDivisorOfArrayTestSuite,
    FindGreatestCommonDivisorOfArrayTest,
    ::testing::ValuesIn(
        FindGreatestCommonDivisorOfArraySolution().getStrategyNames()));

}  // namespace problem_1979
}  // namespace leetcode
