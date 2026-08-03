#include <gtest/gtest.h>

#include <vector>

#include "leetcode/problems/smallest-pair-with-different-frequencies.h"

namespace leetcode::problem_3852 {

class SmallestPairWithDifferentFrequenciesTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  SmallestPairWithDifferentFrequenciesSolution solution;

  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(SmallestPairWithDifferentFrequenciesTest, Example1) {
  std::vector<int> nums = {1, 1, 2, 2, 3, 4};
  EXPECT_EQ(solution.minDistinctFreqPair(nums), (std::vector<int>{1, 3}));
}

TEST_P(SmallestPairWithDifferentFrequenciesTest, Example2) {
  std::vector<int> nums = {1, 5};
  EXPECT_EQ(solution.minDistinctFreqPair(nums), (std::vector<int>{-1, -1}));
}

TEST_P(SmallestPairWithDifferentFrequenciesTest, Example3) {
  std::vector<int> nums = {7};
  EXPECT_EQ(solution.minDistinctFreqPair(nums), (std::vector<int>{-1, -1}));
}

TEST_P(SmallestPairWithDifferentFrequenciesTest, SelfAuthoredAllSameFreq) {
  std::vector<int> nums = {1, 1, 2, 2};
  EXPECT_EQ(solution.minDistinctFreqPair(nums), (std::vector<int>{-1, -1}));
}

TEST_P(SmallestPairWithDifferentFrequenciesTest, SelfAuthoredSmallestIsHigherFreq) {
  std::vector<int> nums = {1, 1, 1, 2, 2, 3};
  EXPECT_EQ(solution.minDistinctFreqPair(nums), (std::vector<int>{1, 2}));
}

INSTANTIATE_TEST_SUITE_P(
    SmallestPairWithDifferentFrequenciesTestSuite,
    SmallestPairWithDifferentFrequenciesTest,
    ::testing::ValuesIn(
        SmallestPairWithDifferentFrequenciesSolution().getStrategyNames()));

}  // namespace leetcode::problem_3852
