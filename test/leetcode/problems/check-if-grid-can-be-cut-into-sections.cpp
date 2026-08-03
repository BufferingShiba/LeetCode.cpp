#include <gtest/gtest.h>

#include "leetcode/problems/check-if-grid-can-be-cut-into-sections.h"

#include <string>
#include <vector>

namespace leetcode {
namespace problem_3394 {

class CheckIfGridCanBeCutIntoSectionsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  CheckIfGridCanBeCutIntoSectionsSolution solution_;
};

TEST_P(CheckIfGridCanBeCutIntoSectionsTest, Example1) {
  int n = 5;
  std::vector<std::vector<int>> rectangles = {
      {1, 0, 5, 2}, {0, 2, 2, 4}, {3, 2, 5, 3}, {0, 4, 4, 5}};
  EXPECT_TRUE(solution_.checkValidCuts(n, rectangles));
}

TEST_P(CheckIfGridCanBeCutIntoSectionsTest, Example2) {
  int n = 4;
  std::vector<std::vector<int>> rectangles = {
      {0, 0, 1, 1}, {2, 0, 3, 4}, {0, 2, 2, 3}, {3, 0, 4, 3}};
  EXPECT_TRUE(solution_.checkValidCuts(n, rectangles));
}

TEST_P(CheckIfGridCanBeCutIntoSectionsTest, Example3) {
  int n = 4;
  std::vector<std::vector<int>> rectangles = {
      {0, 2, 2, 4}, {1, 0, 3, 2}, {2, 2, 3, 4}, {3, 0, 4, 2}, {3, 2, 4, 4}};
  EXPECT_FALSE(solution_.checkValidCuts(n, rectangles));
}

TEST_P(CheckIfGridCanBeCutIntoSectionsTest, SelfAuthoredOnlyHorizontalGap) {
  int n = 6;
  std::vector<std::vector<int>> rectangles = {
      {0, 0, 1, 1}, {2, 3, 3, 4}, {4, 5, 5, 6}};
  EXPECT_TRUE(solution_.checkValidCuts(n, rectangles));
}

INSTANTIATE_TEST_SUITE_P(
    CheckIfGridCanBeCutIntoSectionsTestSuite,
    CheckIfGridCanBeCutIntoSectionsTest,
    ::testing::ValuesIn(
        CheckIfGridCanBeCutIntoSectionsSolution().getStrategyNames()));

}  // namespace problem_3394
}  // namespace leetcode
