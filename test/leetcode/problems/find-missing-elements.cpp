#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/find-missing-elements.h"

namespace leetcode {
namespace problem_3731 {

class FindMissingElementsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  FindMissingElementsSolution solution;
};

TEST_P(FindMissingElementsTest, Example1) {
  std::vector<int> nums = {1, 4, 2, 5};
  std::vector<int> expected = {3};
  EXPECT_EQ(solution.findMissingElements(nums), expected);
}

TEST_P(FindMissingElementsTest, Example2) {
  std::vector<int> nums = {7, 8, 6, 9};
  std::vector<int> expected = {};
  EXPECT_EQ(solution.findMissingElements(nums), expected);
}

TEST_P(FindMissingElementsTest, Example3) {
  std::vector<int> nums = {5, 1};
  std::vector<int> expected = {2, 3, 4};
  EXPECT_EQ(solution.findMissingElements(nums), expected);
}

TEST_P(FindMissingElementsTest, SelfAuthoredRangeMiddle) {
  std::vector<int> nums = {1, 10};
  std::vector<int> expected = {2, 3, 4, 5, 6, 7, 8, 9};
  EXPECT_EQ(solution.findMissingElements(nums), expected);
}

INSTANTIATE_TEST_SUITE_P(
    FindMissingElementsTestSuite, FindMissingElementsTest,
    ::testing::ValuesIn(FindMissingElementsSolution().getStrategyNames()));

}  // namespace problem_3731
}  // namespace leetcode
