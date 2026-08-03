#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/count-equal-and-divisible-pairs-in-an-array.h"

namespace leetcode {
namespace problem_2176 {
namespace {

class CountEqualAndDivisiblePairsInAnArrayTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  CountEqualAndDivisiblePairsInAnArraySolution solution_;
};

TEST_P(CountEqualAndDivisiblePairsInAnArrayTest, Example1) {
  std::vector<int> nums{3, 1, 2, 2, 2, 1, 3};
  int k = 2;
  EXPECT_EQ(solution_.countPairs(nums, k), 4);
}

TEST_P(CountEqualAndDivisiblePairsInAnArrayTest, Example2) {
  std::vector<int> nums{1, 2, 3, 4};
  int k = 1;
  EXPECT_EQ(solution_.countPairs(nums, k), 0);
}

TEST_P(CountEqualAndDivisiblePairsInAnArrayTest, SelfAuthoredSingleElement) {
  std::vector<int> nums{5};
  int k = 3;
  EXPECT_EQ(solution_.countPairs(nums, k), 0);
}

INSTANTIATE_TEST_SUITE_P(
    CountEqualAndDivisiblePairsInAnArrayTestSuite,
    CountEqualAndDivisiblePairsInAnArrayTest,
    ::testing::ValuesIn(CountEqualAndDivisiblePairsInAnArraySolution().getStrategyNames()));

}  // namespace
}  // namespace problem_2176
}  // namespace leetcode
