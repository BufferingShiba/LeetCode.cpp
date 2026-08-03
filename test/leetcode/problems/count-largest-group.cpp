#include <gtest/gtest.h>

#include "leetcode/problems/count-largest-group.h"

namespace leetcode::problem_1399 {

class CountLargestGroupTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  CountLargestGroupSolution solution;
};

TEST_P(CountLargestGroupTest, Example1) {
  EXPECT_EQ(solution.countLargestGroup(13), 4);
}

TEST_P(CountLargestGroupTest, Example2) {
  EXPECT_EQ(solution.countLargestGroup(2), 2);
}

TEST_P(CountLargestGroupTest, SelfAuthoredSingleElement) {
  EXPECT_EQ(solution.countLargestGroup(1), 1);
}

INSTANTIATE_TEST_SUITE_P(CountLargestGroupTestCases, CountLargestGroupTest,
                         ::testing::ValuesIn(CountLargestGroupSolution().getStrategyNames()));

}  // namespace leetcode::problem_1399
