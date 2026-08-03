#include <gtest/gtest.h>

#include <string>

#include "leetcode/problems/excel-sheet-column-number.h"

namespace leetcode {
namespace problem_171 {

class ExcelSheetColumnNumberTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  ExcelSheetColumnNumberSolution solution;
};

TEST_P(ExcelSheetColumnNumberTest, Example1) {
  EXPECT_EQ(solution.titleToNumber("A"), 1);
}

TEST_P(ExcelSheetColumnNumberTest, Example2) {
  EXPECT_EQ(solution.titleToNumber("AB"), 28);
}

TEST_P(ExcelSheetColumnNumberTest, Example3) {
  EXPECT_EQ(solution.titleToNumber("ZY"), 701);
}

TEST_P(ExcelSheetColumnNumberTest, SelfAuthoredSingleLetter) {
  EXPECT_EQ(solution.titleToNumber("Z"), 26);
}

TEST_P(ExcelSheetColumnNumberTest, SelfAuthoredFurtherColumns) {
  EXPECT_EQ(solution.titleToNumber("AAA"), 703);
}

INSTANTIATE_TEST_SUITE_P(
    ExcelSheetColumnNumberTestSuite, ExcelSheetColumnNumberTest,
    ::testing::ValuesIn(ExcelSheetColumnNumberSolution().getStrategyNames()));

}  // namespace problem_171
}  // namespace leetcode
