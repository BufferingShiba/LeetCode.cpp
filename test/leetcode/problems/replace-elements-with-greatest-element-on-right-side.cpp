#include <gtest/gtest.h>
#include "leetcode/problems/replace-elements-with-greatest-element-on-right-side.h"

using namespace leetcode::problem_1299;

class ReplaceElementsWithGreatestElementOnRightSideTest : public ::testing::TestWithParam<std::string> {
 protected:
  ReplaceElementsWithGreatestElementOnRightSideSolution solution;

  void SetUp() override {
    solution.setStrategy(GetParam());
  }
};

TEST_P(ReplaceElementsWithGreatestElementOnRightSideTest, Example1) {
  std::vector<int> arr = {17, 18, 5, 4, 6, 1};
  std::vector<int> expected = {18, 6, 6, 6, 1, -1};
  EXPECT_EQ(solution.replaceElements(arr), expected);
}

TEST_P(ReplaceElementsWithGreatestElementOnRightSideTest, Example2) {
  std::vector<int> arr = {400};
  std::vector<int> expected = {-1};
  EXPECT_EQ(solution.replaceElements(arr), expected);
}

TEST_P(ReplaceElementsWithGreatestElementOnRightSideTest, SelfAuthoredTwoElementsDescending) {
  std::vector<int> arr = {5, 3};
  std::vector<int> expected = {3, -1};
  EXPECT_EQ(solution.replaceElements(arr), expected);
}

TEST_P(ReplaceElementsWithGreatestElementOnRightSideTest, SelfAuthoredTwoElementsAscending) {
  std::vector<int> arr = {3, 5};
  std::vector<int> expected = {5, -1};
  EXPECT_EQ(solution.replaceElements(arr), expected);
}

TEST_P(ReplaceElementsWithGreatestElementOnRightSideTest, SelfAuthoredAllSame) {
  std::vector<int> arr = {7, 7, 7};
  std::vector<int> expected = {7, 7, -1};
  EXPECT_EQ(solution.replaceElements(arr), expected);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    ReplaceElementsWithGreatestElementOnRightSideTest,
    ::testing::ValuesIn(ReplaceElementsWithGreatestElementOnRightSideSolution().getStrategyNames()));
