#include <gtest/gtest.h>
#include "leetcode/problems/count-almost-equal-pairs-ii.h"

namespace leetcode::problem_3267 {

class CountAlmostEqualPairsIiTest : public ::testing::TestWithParam<std::string> {
 protected:
  CountAlmostEqualPairsIiSolution solution;

  void SetUp() override {
    solution.setStrategy(GetParam());
  }
};

TEST_P(CountAlmostEqualPairsIiTest, Example1) {
  std::vector<int> nums = {1023, 2310, 2130, 213};
  EXPECT_EQ(solution.countPairs(nums), 4);
}

TEST_P(CountAlmostEqualPairsIiTest, Example2) {
  std::vector<int> nums = {1, 10, 100};
  EXPECT_EQ(solution.countPairs(nums), 3);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    CountAlmostEqualPairsIiTest,
    ::testing::ValuesIn(CountAlmostEqualPairsIiSolution().getStrategyNames()));

}  // namespace leetcode::problem_3267
