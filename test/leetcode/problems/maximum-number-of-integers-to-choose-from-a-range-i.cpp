#include <gtest/gtest.h>

#include "leetcode/problems/maximum-number-of-integers-to-choose-from-a-range-i.h"

namespace leetcode::problem_2554 {

class MaximumNumberOfIntegersToChooseFromARangeITest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MaximumNumberOfIntegersToChooseFromARangeISolution solution;
};

TEST_P(MaximumNumberOfIntegersToChooseFromARangeITest, Example1) {
  std::vector<int> banned = {1, 6, 5};
  EXPECT_EQ(solution.maxCount(banned, 5, 6), 2);
}

TEST_P(MaximumNumberOfIntegersToChooseFromARangeITest, Example2) {
  std::vector<int> banned = {1, 2, 3, 4, 5, 6, 7};
  EXPECT_EQ(solution.maxCount(banned, 8, 1), 0);
}

TEST_P(MaximumNumberOfIntegersToChooseFromARangeITest, Example3) {
  std::vector<int> banned = {11};
  EXPECT_EQ(solution.maxCount(banned, 7, 50), 7);
}

TEST_P(MaximumNumberOfIntegersToChooseFromARangeITest, SelfAuthored_AllAllowed) {
  std::vector<int> banned = {};
  // 1+2+3 = 6, count=3
  EXPECT_EQ(solution.maxCount(banned, 3, 6), 3);
}

TEST_P(MaximumNumberOfIntegersToChooseFromARangeITest, SelfAuthored_LargeGap) {
  std::vector<int> banned = {2, 3, 4};
  // available: 1, 5; 1+5=6 <= 10, count=2
  EXPECT_EQ(solution.maxCount(banned, 5, 10), 2);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    MaximumNumberOfIntegersToChooseFromARangeITest,
    testing::ValuesIn(
        MaximumNumberOfIntegersToChooseFromARangeISolution().getStrategyNames()));

}  // namespace leetcode::problem_2554
