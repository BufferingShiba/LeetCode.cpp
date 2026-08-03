#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/unique-middle-element.h"

namespace leetcode::problem_3978 {

class UniqueMiddleElementTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution_.setStrategy(GetParam());
  }

  UniqueMiddleElementSolution solution_;
};

TEST_P(UniqueMiddleElementTest, Example1) {
  std::vector<int> nums{1, 2, 3};
  EXPECT_TRUE(solution_.isMiddleElementUnique(nums));
}

TEST_P(UniqueMiddleElementTest, Example2) {
  std::vector<int> nums{1, 2, 2};
  EXPECT_FALSE(solution_.isMiddleElementUnique(nums));
}

TEST_P(UniqueMiddleElementTest, SelfAuthoredSingleElement) {
  std::vector<int> nums{7};
  EXPECT_TRUE(solution_.isMiddleElementUnique(nums));
}

TEST_P(UniqueMiddleElementTest, SelfAuthoredMiddleDuplicatedAtStart) {
  std::vector<int> nums{3, 1, 3, 2, 3};
  // middle element is 3, appears at indices 0, 2, 4 => false
  EXPECT_FALSE(solution_.isMiddleElementUnique(nums));
}

INSTANTIATE_TEST_SUITE_P(
    UniqueMiddleElementTestSuite, UniqueMiddleElementTest,
    ::testing::ValuesIn(UniqueMiddleElementSolution().getStrategyNames()));

}  // namespace leetcode::problem_3978
