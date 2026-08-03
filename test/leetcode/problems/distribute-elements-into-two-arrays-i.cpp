#include <gtest/gtest.h>

#include "leetcode/problems/distribute-elements-into-two-arrays-i.h"

#include <string>
#include <vector>

namespace leetcode {
namespace problem_3069 {

class DistributeElementsIntoTwoArraysITest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  DistributeElementsIntoTwoArraysISolution solution;
};

TEST_P(DistributeElementsIntoTwoArraysITest, Example1) {
  std::vector<int> nums = {2, 1, 3};
  std::vector<int> expected = {2, 3, 1};
  EXPECT_EQ(expected, solution.resultArray(nums));
}

TEST_P(DistributeElementsIntoTwoArraysITest, Example2) {
  std::vector<int> nums = {5, 4, 3, 8};
  std::vector<int> expected = {5, 3, 4, 8};
  EXPECT_EQ(expected, solution.resultArray(nums));
}

TEST_P(DistributeElementsIntoTwoArraysITest, SelfAuthored) {
  // All elements must be distinct, length >= 3.
  // arr1 starts with 4, arr2 starts with 1.
  // 2: 4>1 -> arr1=[4,2]
  // 3: 2>1 -> arr1=[4,2,3]
  // 5: 3>1 -> arr1=[4,2,3,5]
  std::vector<int> nums = {4, 1, 2, 3, 5};
  std::vector<int> expected = {4, 2, 3, 5, 1};
  EXPECT_EQ(expected, solution.resultArray(nums));
}

INSTANTIATE_TEST_SUITE_P(
    DistributeElementsIntoTwoArraysITestSuite,
    DistributeElementsIntoTwoArraysITest,
    ::testing::ValuesIn(
        DistributeElementsIntoTwoArraysISolution().getStrategyNames()));

}  // namespace problem_3069
}  // namespace leetcode
