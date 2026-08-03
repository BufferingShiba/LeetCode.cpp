#include <gtest/gtest.h>

#include "leetcode/problems/minimum-score-by-changing-two-elements.h"

namespace leetcode {
namespace problem_2567 {

class MinimumScoreByChangingTwoElementsTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }
  MinimumScoreByChangingTwoElementsSolution solution;
};

TEST_P(MinimumScoreByChangingTwoElementsTest, Example1) {
  std::vector<int> nums = {1, 4, 7, 8, 5};
  EXPECT_EQ(solution.minimizeSum(nums), 3);
}

TEST_P(MinimumScoreByChangingTwoElementsTest, Example2) {
  std::vector<int> nums = {1, 4, 3};
  EXPECT_EQ(solution.minimizeSum(nums), 0);
}

TEST_P(MinimumScoreByChangingTwoElementsTest, SelfAuthoredMinimumSizeAllSame) {
  std::vector<int> nums = {5, 5, 5};
  EXPECT_EQ(solution.minimizeSum(nums), 0);
}

TEST_P(MinimumScoreByChangingTwoElementsTest, SelfAuthoredArbitraryCase) {
  std::vector<int> nums = {1, 10, 100, 1000};
  // sorted: 1, 10, 100, 1000
  // remove two smallest: 1000-100=900
  // remove two largest: 10-1=9
  // remove one each: 100-10=90
  // min = 9
  EXPECT_EQ(solution.minimizeSum(nums), 9);
}

INSTANTIATE_TEST_SUITE_P(
    AllStrategies,
    MinimumScoreByChangingTwoElementsTest,
    testing::ValuesIn(
        MinimumScoreByChangingTwoElementsSolution().getStrategyNames()));

}  // namespace problem_2567
}  // namespace leetcode
