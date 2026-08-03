#include "leetcode/problems/element-appearing-more-than-25-in-sorted-array.h"

#include <gtest/gtest.h>

#include <string>
#include <vector>

namespace leetcode {
namespace problem_1287 {

class ElementAppearingMoreThan25InSortedArrayTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  ElementAppearingMoreThan25InSortedArraySolution solution;
};

TEST_P(ElementAppearingMoreThan25InSortedArrayTest, Example1) {
  std::vector<int> arr = {1, 2, 2, 6, 6, 6, 6, 7, 10};
  EXPECT_EQ(6, solution.findSpecialInteger(arr));
}

TEST_P(ElementAppearingMoreThan25InSortedArrayTest, Example2) {
  std::vector<int> arr = {1, 1};
  EXPECT_EQ(1, solution.findSpecialInteger(arr));
}

TEST_P(ElementAppearingMoreThan25InSortedArrayTest, SelfAuthoredSingleElement) {
  std::vector<int> arr = {5};
  EXPECT_EQ(5, solution.findSpecialInteger(arr));
}

TEST_P(ElementAppearingMoreThan25InSortedArrayTest, SelfAuthoredThreeTimesFourth) {
  std::vector<int> arr = {1, 2, 2, 2, 3};
  EXPECT_EQ(2, solution.findSpecialInteger(arr));
}

INSTANTIATE_TEST_SUITE_P(
    ElementAppearingMoreThan25InSortedArrayTestSuite,
    ElementAppearingMoreThan25InSortedArrayTest,
    ::testing::ValuesIn(
        ElementAppearingMoreThan25InSortedArraySolution().getStrategyNames()));

}  // namespace problem_1287
}  // namespace leetcode
