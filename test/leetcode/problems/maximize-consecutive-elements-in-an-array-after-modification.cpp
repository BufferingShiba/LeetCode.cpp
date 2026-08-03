#include <gtest/gtest.h>

#include <algorithm>
#include <string>
#include <vector>

#include "leetcode/problems/maximize-consecutive-elements-in-an-array-after-modification.h"

namespace leetcode::problem_3041 {

class MaximizeConsecutiveElementsInAnArrayAfterModificationTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution.setStrategy(GetParam());
  }

  MaximizeConsecutiveElementsInAnArrayAfterModificationSolution solution;
};

TEST_P(MaximizeConsecutiveElementsInAnArrayAfterModificationTest, Example1) {
  std::vector<int> nums{2, 1, 5, 1, 1};
  EXPECT_EQ(solution.maxSelectedElements(nums), 3);
}

TEST_P(MaximizeConsecutiveElementsInAnArrayAfterModificationTest, Example2) {
  std::vector<int> nums{1, 4, 7, 10};
  EXPECT_EQ(solution.maxSelectedElements(nums), 1);
}

TEST_P(MaximizeConsecutiveElementsInAnArrayAfterModificationTest, DuplicateValuesCanExtendBothSides) {
  std::vector<int> nums{1, 1, 1, 2, 5};
  EXPECT_EQ(solution.maxSelectedElements(nums), 3);
}

TEST_P(MaximizeConsecutiveElementsInAnArrayAfterModificationTest, GappedValues) {
  std::vector<int> nums{2, 3, 6, 8, 9, 10, 11, 12, 13, 16, 18, 19};
  EXPECT_EQ(solution.maxSelectedElements(nums), 7);
}

TEST_P(MaximizeConsecutiveElementsInAnArrayAfterModificationTest, SingleElement) {
  std::vector<int> nums{100};
  EXPECT_EQ(solution.maxSelectedElements(nums), 1);
}

INSTANTIATE_TEST_SUITE_P(
    MaximizeConsecutiveElementsInAnArrayAfterModification,
    MaximizeConsecutiveElementsInAnArrayAfterModificationTest,
    ::testing::ValuesIn(
        MaximizeConsecutiveElementsInAnArrayAfterModificationSolution().getStrategyNames()));

}  // namespace leetcode::problem_3041
