#include "leetcode/problems/maximum-sum-of-three-numbers-divisible-by-three.h"

#include <gtest/gtest.h>

#include <string>
#include <vector>

namespace leetcode {
namespace problem_3780 {
namespace {

class MaximumSumOfThreeNumbersDivisibleByThreeTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  MaximumSumOfThreeNumbersDivisibleByThreeSolution solution;

  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(MaximumSumOfThreeNumbersDivisibleByThreeTest, Example1) {
  std::vector<int> nums{4, 2, 3, 1};
  EXPECT_EQ(9, solution.maximumSum(nums));
}

TEST_P(MaximumSumOfThreeNumbersDivisibleByThreeTest, Example2) {
  std::vector<int> nums{2, 1, 5};
  EXPECT_EQ(0, solution.maximumSum(nums));
}

TEST_P(MaximumSumOfThreeNumbersDivisibleByThreeTest, SelfAuthoredAllDivisibleByThree) {
  std::vector<int> nums{3, 6, 9, 12};
  EXPECT_EQ(27, solution.maximumSum(nums));
}

TEST_P(MaximumSumOfThreeNumbersDivisibleByThreeTest, SelfAuthoredRemainderOnesOnly) {
  // 3 numbers all with remainder 1: 1+1+1=3 divisible by 3.
  std::vector<int> nums{1, 1, 1};
  EXPECT_EQ(3, solution.maximumSum(nums));
}

TEST_P(MaximumSumOfThreeNumbersDivisibleByThreeTest, SelfAuthoredLargeValuesThreshold) {
  std::vector<int> nums{100000, 99999, 99998};
  // 100000%3=1, 99999%3=0, 99998%3=2 -> sum divisible by 3.
  EXPECT_EQ(299997, solution.maximumSum(nums));
}

INSTANTIATE_TEST_SUITE_P(
    MaximumSumOfThreeNumbersDivisibleByThreeTestSuite,
    MaximumSumOfThreeNumbersDivisibleByThreeTest,
    ::testing::ValuesIn(
        MaximumSumOfThreeNumbersDivisibleByThreeSolution()
            .getStrategyNames()));

}  // namespace
}  // namespace problem_3780
}  // namespace leetcode
