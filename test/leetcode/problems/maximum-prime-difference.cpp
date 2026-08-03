#include "leetcode/problems/maximum-prime-difference.h"
#include <gtest/gtest.h>

namespace leetcode {
namespace problem_3115 {

class MaximumPrimeDifferenceTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  MaximumPrimeDifferenceSolution solution_;
};

TEST_P(MaximumPrimeDifferenceTest, Example1) {
  std::vector<int> nums = {4, 2, 9, 5, 3};
  EXPECT_EQ(3, solution_.getSolution()(nums));
}

TEST_P(MaximumPrimeDifferenceTest, Example2) {
  std::vector<int> nums = {4, 8, 2, 8};
  EXPECT_EQ(0, solution_.getSolution()(nums));
}

TEST_P(MaximumPrimeDifferenceTest, SelfAuthoredPrimeAtBothEnds) {
  std::vector<int> nums = {2, 4, 6, 8, 10, 12, 3};
  EXPECT_EQ(6, solution_.getSolution()(nums));
}

TEST_P(MaximumPrimeDifferenceTest, SelfAuthoredSingleElementPrime) {
  std::vector<int> nums = {7};
  EXPECT_EQ(0, solution_.getSolution()(nums));
}

INSTANTIATE_TEST_SUITE_P(
    MaximumPrimeDifferenceTestSuite, MaximumPrimeDifferenceTest,
    ::testing::ValuesIn(MaximumPrimeDifferenceSolution().getStrategyNames()));

}  // namespace problem_3115
}  // namespace leetcode
