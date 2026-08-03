#include <gtest/gtest.h>

#include "leetcode/problems/count-partitions-with-even-sum-difference.h"

namespace leetcode::problem_3432 {

class CountPartitionsWithEvenSumDifferenceTest : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }
  CountPartitionsWithEvenSumDifferenceSolution solution_;
};

TEST_P(CountPartitionsWithEvenSumDifferenceTest, Example1) {
  std::vector<int> nums = {10, 10, 3, 7, 6};
  EXPECT_EQ(solution_.countPartitions(nums), 4);
}

TEST_P(CountPartitionsWithEvenSumDifferenceTest, Example2) {
  std::vector<int> nums = {1, 2, 2};
  EXPECT_EQ(solution_.countPartitions(nums), 0);
}

TEST_P(CountPartitionsWithEvenSumDifferenceTest, Example3) {
  std::vector<int> nums = {2, 4, 6, 8};
  EXPECT_EQ(solution_.countPartitions(nums), 3);
}

TEST_P(CountPartitionsWithEvenSumDifferenceTest, SelfAuthoredOddTotal) {
  std::vector<int> nums = {1, 2, 3, 4, 5};
  // total = 15 (odd), expected 0
  EXPECT_EQ(solution_.countPartitions(nums), 0);
}

TEST_P(CountPartitionsWithEvenSumDifferenceTest, SelfAuthoredEvenTotal) {
  std::vector<int> nums = {1, 2, 3, 4};
  // total = 10 (even), n=4, expected 3
  EXPECT_EQ(solution_.countPartitions(nums), 3);
}

INSTANTIATE_TEST_SUITE_P(Strategies,
                         CountPartitionsWithEvenSumDifferenceTest,
                         testing::ValuesIn(CountPartitionsWithEvenSumDifferenceSolution().getStrategyNames()));

}  // namespace leetcode::problem_3432
