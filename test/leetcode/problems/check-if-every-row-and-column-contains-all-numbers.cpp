#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/check-if-every-row-and-column-contains-all-numbers.h"

namespace leetcode {
namespace problem_2133 {

namespace {

using SolutionType = CheckIfEveryRowAndColumnContainsAllNumbersSolution;

}  // namespace

class CheckIfEveryRowAndColumnContainsAllNumbersTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  SolutionType solution;
};

TEST_P(CheckIfEveryRowAndColumnContainsAllNumbersTest, Example1) {
  std::vector<std::vector<int>> matrix = {{1, 2, 3}, {3, 1, 2}, {2, 3, 1}};
  EXPECT_TRUE(solution.checkValid(matrix));
}

TEST_P(CheckIfEveryRowAndColumnContainsAllNumbersTest, Example2) {
  std::vector<std::vector<int>> matrix = {{1, 1, 1}, {1, 2, 3}, {1, 2, 3}};
  EXPECT_FALSE(solution.checkValid(matrix));
}

TEST_P(CheckIfEveryRowAndColumnContainsAllNumbersTest, SelfAuthoredSingleElement) {
  std::vector<std::vector<int>> matrix = {{1}};
  EXPECT_TRUE(solution.checkValid(matrix));
}

TEST_P(CheckIfEveryRowAndColumnContainsAllNumbersTest, SelfAuthoredDuplicateInColumn) {
  std::vector<std::vector<int>> matrix = {{1, 2, 3}, {2, 1, 3}, {3, 2, 1}};
  EXPECT_FALSE(solution.checkValid(matrix));
}

INSTANTIATE_TEST_SUITE_P(
    CheckIfEveryRowAndColumnContainsAllNumbersTestSuite,
    CheckIfEveryRowAndColumnContainsAllNumbersTest,
    ::testing::ValuesIn(SolutionType().getStrategyNames()));

}  // namespace problem_2133
}  // namespace leetcode
