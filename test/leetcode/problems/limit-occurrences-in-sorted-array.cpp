#include "leetcode/problems/limit-occurrences-in-sorted-array.h"

#include <gtest/gtest.h>

#include <string>
#include <vector>

namespace leetcode::problem_3940 {

class LimitOccurrencesInSortedArrayTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  LimitOccurrencesInSortedArraySolution solution_;
};

TEST_P(LimitOccurrencesInSortedArrayTest, Example1) {
  std::vector<int> nums{1, 1, 1, 2, 2, 3};
  std::vector<int> expected{1, 1, 2, 2, 3};
  auto result = solution_.limitOccurrences(nums, 2);
  EXPECT_EQ(result, expected);
}

TEST_P(LimitOccurrencesInSortedArrayTest, Example2) {
  std::vector<int> nums{1, 2, 3};
  std::vector<int> expected{1, 2, 3};
  auto result = solution_.limitOccurrences(nums, 1);
  EXPECT_EQ(result, expected);
}

TEST_P(LimitOccurrencesInSortedArrayTest, AllSameMoreThanK) {
  std::vector<int> nums{5, 5, 5, 5};
  std::vector<int> expected{5, 5};
  auto result = solution_.limitOccurrences(nums, 2);
  EXPECT_EQ(result, expected);
}

TEST_P(LimitOccurrencesInSortedArrayTest, KEqualsLength) {
  std::vector<int> nums{1, 1, 2, 2, 3, 3};
  std::vector<int> expected{1, 1, 2, 2, 3, 3};
  auto result = solution_.limitOccurrences(nums, 6);
  EXPECT_EQ(result, expected);
}

INSTANTIATE_TEST_SUITE_P(
    LimitOccurrencesInSortedArrayTestSuite,
    LimitOccurrencesInSortedArrayTest,
    ::testing::ValuesIn(
        LimitOccurrencesInSortedArraySolution().getStrategyNames()));

}  // namespace leetcode::problem_3940
