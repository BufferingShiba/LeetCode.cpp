#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/number-of-distinct-averages.h"

namespace leetcode::problem_2465 {

class NumberOfDistinctAveragesTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  NumberOfDistinctAveragesSolution solution;
};

TEST_P(NumberOfDistinctAveragesTest, Example1) {
  std::vector<int> nums{4, 1, 4, 0, 3, 5};
  EXPECT_EQ(solution.distinctAverages(nums), 2);
}

TEST_P(NumberOfDistinctAveragesTest, Example2) {
  std::vector<int> nums{1, 100};
  EXPECT_EQ(solution.distinctAverages(nums), 1);
}

TEST_P(NumberOfDistinctAveragesTest, SelfAuthoredAllDistinct) {
  std::vector<int> nums{0, 1, 2, 3};
  // (0+3)/2=1.5, (1+2)/2=1.5 -> only 1 distinct average
  EXPECT_EQ(solution.distinctAverages(nums), 1);
}

TEST_P(NumberOfDistinctAveragesTest, SelfAuthoredTwoPairs) {
  std::vector<int> nums{0, 0, 3, 100};
  // (0+100)/2=50, (0+3)/2=1.5 -> 2 distinct
  EXPECT_EQ(solution.distinctAverages(nums), 2);
}

INSTANTIATE_TEST_SUITE_P(
    NumberOfDistinctAveragesTestCases, NumberOfDistinctAveragesTest,
    ::testing::ValuesIn(NumberOfDistinctAveragesSolution().getStrategyNames()));

}  // namespace leetcode::problem_2465
