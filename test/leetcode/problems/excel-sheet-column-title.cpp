#include <gtest/gtest.h>

#include <string>

#include "leetcode/problems/excel-sheet-column-title.h"

namespace leetcode {
namespace problem_168 {

class ExcelSheetColumnTitleTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution.setStrategy(GetParam());
  }

  ExcelSheetColumnTitleSolution solution;
};

TEST_P(ExcelSheetColumnTitleTest, Example1) {
  EXPECT_EQ(solution.convertToTitle(1), "A");
}

TEST_P(ExcelSheetColumnTitleTest, Example2) {
  EXPECT_EQ(solution.convertToTitle(28), "AB");
}

TEST_P(ExcelSheetColumnTitleTest, Example3) {
  EXPECT_EQ(solution.convertToTitle(701), "ZY");
}

TEST_P(ExcelSheetColumnTitleTest, SelfAuthoredBoundary26) {
  EXPECT_EQ(solution.convertToTitle(26), "Z");
}

TEST_P(ExcelSheetColumnTitleTest, SelfAuthoredBoundary702) {
  EXPECT_EQ(solution.convertToTitle(702), "ZZ");
}

TEST_P(ExcelSheetColumnTitleTest, SelfAuthoredBoundary2147483647) {
  EXPECT_EQ(solution.convertToTitle(2147483647), "FXSHRXW");
}

INSTANTIATE_TEST_SUITE_P(
    ExcelSheetColumnTitleTestInstance, ExcelSheetColumnTitleTest,
    ::testing::ValuesIn(ExcelSheetColumnTitleSolution().getStrategyNames()));

}  // namespace problem_168
}  // namespace leetcode
