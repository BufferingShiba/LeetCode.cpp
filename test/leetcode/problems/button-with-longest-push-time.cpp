#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/button-with-longest-push-time.h"

namespace leetcode {
namespace problem_3386 {
namespace {

class ButtonWithLongestPushTimeTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  ButtonWithLongestPushTimeSolution solution;
};

TEST_P(ButtonWithLongestPushTimeTest, Example1) {
  std::vector<std::vector<int>> events = {{1, 2}, {2, 5}, {3, 9}, {1, 15}};
  EXPECT_EQ(1, solution.buttonWithLongestTime(events));
}

TEST_P(ButtonWithLongestPushTimeTest, Example2) {
  std::vector<std::vector<int>> events = {{10, 5}, {1, 7}};
  EXPECT_EQ(10, solution.buttonWithLongestTime(events));
}

TEST_P(ButtonWithLongestPushTimeTest, SelfAuthoredSingleEvent) {
  std::vector<std::vector<int>> events = {{5, 3}};
  EXPECT_EQ(5, solution.buttonWithLongestTime(events));
}

TEST_P(ButtonWithLongestPushTimeTest, SelfAuthoredTieSmallestIndex) {
  std::vector<std::vector<int>> events = {{3, 1}, {7, 6}, {2, 11}};
  // button3:1, button7:5, button2:5 -> tie (7,2) -> smaller index 2
  EXPECT_EQ(2, solution.buttonWithLongestTime(events));
}

INSTANTIATE_TEST_SUITE_P(
    ButtonWithLongestPushTimeTestSuite, ButtonWithLongestPushTimeTest,
    ::testing::ValuesIn(ButtonWithLongestPushTimeSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_3386
}  // namespace leetcode
