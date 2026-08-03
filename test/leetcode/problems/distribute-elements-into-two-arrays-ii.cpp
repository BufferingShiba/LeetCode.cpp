#include "leetcode/problems/distribute-elements-into-two-arrays-ii.h"

#include <gtest/gtest.h>

#include <string>
#include <vector>

namespace leetcode {
namespace problem_3072 {

using ::testing::TestWithParam;
using ::testing::ValuesIn;

class DistributeElementsIntoTwoArraysIiTest
    : public TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  DistributeElementsIntoTwoArraysIiSolution solution;
};

TEST_P(DistributeElementsIntoTwoArraysIiTest, Example1) {
  std::vector<int> nums = {2, 1, 3, 3};
  std::vector<int> expected = {2, 3, 1, 3};
  EXPECT_EQ(expected, solution.resultArray(nums));
}

TEST_P(DistributeElementsIntoTwoArraysIiTest, Example2) {
  std::vector<int> nums = {5, 14, 3, 1, 2};
  std::vector<int> expected = {5, 3, 1, 2, 14};
  EXPECT_EQ(expected, solution.resultArray(nums));
}

TEST_P(DistributeElementsIntoTwoArraysIiTest, Example3) {
  std::vector<int> nums = {3, 3, 3, 3};
  std::vector<int> expected = {3, 3, 3, 3};
  EXPECT_EQ(expected, solution.resultArray(nums));
}

TEST_P(DistributeElementsIntoTwoArraysIiTest, SelfAuthoredMinLengthTwoPushTie) {
  // n=3: after [a],[b]; third element has equal greaterCount=0, lengths equal
  // -> goes to arr1.
  std::vector<int> nums = {1, 2, 3};
  std::vector<int> expected = {1, 3, 2};
  EXPECT_EQ(expected, solution.resultArray(nums));
}

INSTANTIATE_TEST_SUITE_P(
    DistributeElementsIntoTwoArraysIiTests, DistributeElementsIntoTwoArraysIiTest,
    ValuesIn(DistributeElementsIntoTwoArraysIiSolution().getStrategyNames()));

}  // namespace problem_3072
}  // namespace leetcode
