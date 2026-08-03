#include <gtest/gtest.h>

#include "leetcode/problems/count-number-of-bad-pairs.h"

namespace leetcode::problem_2364 {

class CountNumberOfBadPairsTest : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  CountNumberOfBadPairsSolution solution;
};

TEST_P(CountNumberOfBadPairsTest, Example1) {
  std::vector<int> nums = {4, 1, 3, 3};
  EXPECT_EQ(solution.countBadPairs(nums), 5);
}

TEST_P(CountNumberOfBadPairsTest, Example2) {
  std::vector<int> nums = {1, 2, 3, 4, 5};
  EXPECT_EQ(solution.countBadPairs(nums), 0);
}

TEST_P(CountNumberOfBadPairsTest, SelfAuthoredSingleElement) {
  std::vector<int> nums = {10};
  EXPECT_EQ(solution.countBadPairs(nums), 0);
}

TEST_P(CountNumberOfBadPairsTest, SelfAuthoredAllSameDiff) {
  // nums[i] = i => diff = 0 for all, all pairs are good, 0 bad
  std::vector<int> nums = {0, 1, 2, 3, 4};
  EXPECT_EQ(solution.countBadPairs(nums), 0);
}

TEST_P(CountNumberOfBadPairsTest, SelfAuthoredAllDistinctDiff) {
  // Every diff is unique => no good pairs, all pairs bad
  // nums = [100, 200, 300], diff = [-100, -199, -298] all distinct
  std::vector<int> nums = {100, 200, 300};
  // total = 3*2/2 = 3, all bad
  EXPECT_EQ(solution.countBadPairs(nums), 3);
}

INSTANTIATE_TEST_SUITE_P(Strategies, CountNumberOfBadPairsTest,
                         testing::ValuesIn(CountNumberOfBadPairsSolution().getStrategyNames()));

}  // namespace leetcode::problem_2364
