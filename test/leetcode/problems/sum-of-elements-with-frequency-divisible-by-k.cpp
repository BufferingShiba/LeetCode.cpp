#include <gtest/gtest.h>

#include "leetcode/problems/sum-of-elements-with-frequency-divisible-by-k.h"

#include <string>
#include <vector>

namespace leetcode::problem_3712 {

class SumOfElementsWithFrequencyDivisibleByKTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution.setStrategy(GetParam());
  }

  SumOfElementsWithFrequencyDivisibleByKSolution solution;
};

TEST_P(SumOfElementsWithFrequencyDivisibleByKTest, Example1) {
  std::vector<int> nums{1, 2, 2, 3, 3, 3, 3, 4};
  ASSERT_EQ(solution.sumDivisibleByK(nums, 2), 16);
}

TEST_P(SumOfElementsWithFrequencyDivisibleByKTest, Example2) {
  std::vector<int> nums{1, 2, 3, 4, 5};
  ASSERT_EQ(solution.sumDivisibleByK(nums, 2), 0);
}

TEST_P(SumOfElementsWithFrequencyDivisibleByKTest, Example3) {
  std::vector<int> nums{4, 4, 4, 1, 2, 3};
  ASSERT_EQ(solution.sumDivisibleByK(nums, 3), 12);
}

INSTANTIATE_TEST_SUITE_P(
    SumOfElementsWithFrequencyDivisibleByKSuite,
    SumOfElementsWithFrequencyDivisibleByKTest,
    ::testing::ValuesIn(
        SumOfElementsWithFrequencyDivisibleByKSolution()
            .getStrategyNames()));

}  // namespace leetcode::problem_3712
