#include <gtest/gtest.h>

#include "leetcode/problems/count-indices-with-opposite-parity.h"

#include <string>
#include <vector>

namespace leetcode::problem_3917 {

class CountIndicesWithOppositeParityTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  CountIndicesWithOppositeParitySolution solution;
};

TEST_P(CountIndicesWithOppositeParityTest, Example1) {
  std::vector<int> nums{1, 2, 3, 4};
  std::vector<int> expected{2, 1, 1, 0};
  EXPECT_EQ(expected, solution.countOppositeParity(nums));
}

TEST_P(CountIndicesWithOppositeParityTest, Example2) {
  std::vector<int> nums{1};
  std::vector<int> expected{0};
  EXPECT_EQ(expected, solution.countOppositeParity(nums));
}

TEST_P(CountIndicesWithOppositeParityTest, SelfAuthoredAllSameParity) {
  std::vector<int> nums{2, 4, 6};
  std::vector<int> expected{0, 0, 0};
  EXPECT_EQ(expected, solution.countOppositeParity(nums));
}

TEST_P(CountIndicesWithOppositeParityTest, SelfAuthoredMixedParity) {
  std::vector<int> nums{2, 1, 2};
  std::vector<int> expected{1, 1, 0};
  EXPECT_EQ(expected, solution.countOppositeParity(nums));
}

INSTANTIATE_TEST_SUITE_P(
    CountIndicesWithOppositeParityTestSuite,
    CountIndicesWithOppositeParityTest,
    ::testing::ValuesIn(
        CountIndicesWithOppositeParitySolution().getStrategyNames()));

}  // namespace leetcode::problem_3917
