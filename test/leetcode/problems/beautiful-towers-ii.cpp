#include "leetcode/problems/beautiful-towers-ii.h"

#include <gtest/gtest.h>

namespace leetcode::problem_2866 {

class BeautifulTowersIiTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution.setStrategy(GetParam());
  }

  BeautifulTowersIiSolution solution;
};

TEST_P(BeautifulTowersIiTest, Example1) {
  std::vector<int> maxHeights = {5, 3, 4, 1, 1};
  EXPECT_EQ(13, solution.call(maxHeights));
}

TEST_P(BeautifulTowersIiTest, Example2) {
  std::vector<int> maxHeights = {6, 5, 3, 9, 2, 7};
  EXPECT_EQ(22, solution.call(maxHeights));
}

TEST_P(BeautifulTowersIiTest, Example3) {
  std::vector<int> maxHeights = {3, 2, 5, 5, 2, 3};
  EXPECT_EQ(18, solution.call(maxHeights));
}

TEST_P(BeautifulTowersIiTest, SingleElement) {
  std::vector<int> maxHeights = {7};
  EXPECT_EQ(7, solution.call(maxHeights));
}

TEST_P(BeautifulTowersIiTest, AllEqual) {
  std::vector<int> maxHeights = {4, 4, 4, 4};
  EXPECT_EQ(16, solution.call(maxHeights));
}

INSTANTIATE_TEST_SUITE_P(
    BeautifulTowersIiTestSuite, BeautifulTowersIiTest,
    ::testing::ValuesIn(BeautifulTowersIiSolution().getStrategyNames()));

}  // namespace leetcode::problem_2866
