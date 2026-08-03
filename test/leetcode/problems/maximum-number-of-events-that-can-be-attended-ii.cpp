#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/maximum-number-of-events-that-can-be-attended-ii.h"

namespace leetcode {
namespace problem_1751 {

class MaximumNumberOfEventsThatCanBeAttendedIiTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MaximumNumberOfEventsThatCanBeAttendedIiSolution solution;
};

TEST_P(MaximumNumberOfEventsThatCanBeAttendedIiTest, Example1) {
  auto events = std::vector<std::vector<int>>{
      {1, 2, 4}, {3, 4, 3}, {2, 3, 1}};
  EXPECT_EQ(7, solution.maxValue(events, 2));
}

TEST_P(MaximumNumberOfEventsThatCanBeAttendedIiTest, Example2) {
  auto events = std::vector<std::vector<int>>{
      {1, 2, 4}, {3, 4, 3}, {2, 3, 10}};
  EXPECT_EQ(10, solution.maxValue(events, 2));
}

TEST_P(MaximumNumberOfEventsThatCanBeAttendedIiTest, Example3) {
  auto events = std::vector<std::vector<int>>{
      {1, 1, 1}, {2, 2, 2}, {3, 3, 3}, {4, 4, 4}};
  EXPECT_EQ(9, solution.maxValue(events, 3));
}

TEST_P(MaximumNumberOfEventsThatCanBeAttendedIiTest, SelfAuthoredKEqualsOneTakeMax) {
  auto events = std::vector<std::vector<int>>{
      {1, 2, 5}, {2, 4, 7}, {5, 6, 3}};
  EXPECT_EQ(7, solution.maxValue(events, 1));
}

INSTANTIATE_TEST_SUITE_P(
    MaximumNumberOfEventsThatCanBeAttendedIiTestSuite,
    MaximumNumberOfEventsThatCanBeAttendedIiTest,
    ::testing::ValuesIn(
        MaximumNumberOfEventsThatCanBeAttendedIiSolution().getStrategyNames()));

}  // namespace problem_1751
}  // namespace leetcode
