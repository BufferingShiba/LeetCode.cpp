#include "leetcode/problems/check-if-grid-satisfies-conditions.h"
#include <gtest/gtest.h>

namespace leetcode {
namespace problem_3142 {
namespace {

class CheckIfGridSatisfiesConditionsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }
  CheckIfGridSatisfiesConditionsSolution solution_;
};

TEST_P(CheckIfGridSatisfiesConditionsTest, Example1) {
  std::vector<std::vector<int>> grid = {{1, 0, 2}, {1, 0, 2}};
  EXPECT_TRUE(solution_.getSolution()(grid));
}

TEST_P(CheckIfGridSatisfiesConditionsTest, Example2) {
  std::vector<std::vector<int>> grid = {{1, 1, 1}, {0, 0, 0}};
  EXPECT_FALSE(solution_.getSolution()(grid));
}

TEST_P(CheckIfGridSatisfiesConditionsTest, Example3) {
  std::vector<std::vector<int>> grid = {{1}, {2}, {3}};
  EXPECT_FALSE(solution_.getSolution()(grid));
}

TEST_P(CheckIfGridSatisfiesConditionsTest, SelfAuthoredSingleCell) {
  std::vector<std::vector<int>> grid = {{5}};
  EXPECT_TRUE(solution_.getSolution()(grid));
}

TEST_P(CheckIfGridSatisfiesConditionsTest, SelfAuthoredTwoRowsDifferent) {
  std::vector<std::vector<int>> grid = {{1, 2}, {3, 4}};
  EXPECT_FALSE(solution_.getSolution()(grid));
}

INSTANTIATE_TEST_SUITE_P(
    CheckIfGridSatisfiesConditionsTestSuite,
    CheckIfGridSatisfiesConditionsTest,
    ::testing::ValuesIn(CheckIfGridSatisfiesConditionsSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_3142
}  // namespace leetcode
