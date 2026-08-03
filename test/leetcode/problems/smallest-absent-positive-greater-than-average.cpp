#include "leetcode/problems/smallest-absent-positive-greater-than-average.h"

#include <gtest/gtest.h>

#include <string>
#include <vector>

namespace leetcode {
namespace problem_3678 {

class SmallestAbsentPositiveGreaterThanAverageTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  SmallestAbsentPositiveGreaterThanAverageSolution solution;
};

TEST_P(SmallestAbsentPositiveGreaterThanAverageTest, Example1) {
  std::vector<int> nums = {3, 5};
  EXPECT_EQ(solution.smallestAbsent(nums), 6);
}

TEST_P(SmallestAbsentPositiveGreaterThanAverageTest, Example2) {
  std::vector<int> nums = {-1, 1, 2};
  EXPECT_EQ(solution.smallestAbsent(nums), 3);
}

TEST_P(SmallestAbsentPositiveGreaterThanAverageTest, Example3) {
  std::vector<int> nums = {4, -1};
  EXPECT_EQ(solution.smallestAbsent(nums), 2);
}

TEST_P(SmallestAbsentPositiveGreaterThanAverageTest, SelfAuthoredAllZero) {
  std::vector<int> nums = {0, 0, 0};
  // avg = 0, smallest positive > 0 is 1, and 1 not present.
  EXPECT_EQ(solution.smallestAbsent(nums), 1);
}

TEST_P(SmallestAbsentPositiveGreaterThanAverageTest, SelfAuthoredPresentFromStart) {
  std::vector<int> nums = {1, 2, 3, 6};
  // avg = 12/4 = 3, smallest positive > 3 is 4, absent in nums.
  EXPECT_EQ(solution.smallestAbsent(nums), 4);
}

INSTANTIATE_TEST_SUITE_P(
    SmallestAbsentPositiveGreaterThanAverageTestSuite,
    SmallestAbsentPositiveGreaterThanAverageTest,
    ::testing::ValuesIn(
        SmallestAbsentPositiveGreaterThanAverageSolution().getStrategyNames()));

}  // namespace problem_3678
}  // namespace leetcode
