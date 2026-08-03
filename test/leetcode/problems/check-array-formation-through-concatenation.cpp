#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/check-array-formation-through-concatenation.h"

namespace leetcode::problem_1640 {

using leetcode::problem_1640::CheckArrayFormationThroughConcatenationSolution;

class CheckArrayFormationThroughConcatenationTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  CheckArrayFormationThroughConcatenationSolution solution_;
};

TEST_P(CheckArrayFormationThroughConcatenationTest, Example1) {
  std::vector<int> arr = {15, 88};
  std::vector<std::vector<int>> pieces = {{88}, {15}};
  EXPECT_TRUE(solution_.canFormArray(arr, pieces));
}

TEST_P(CheckArrayFormationThroughConcatenationTest, Example2) {
  std::vector<int> arr = {49, 18, 16};
  std::vector<std::vector<int>> pieces = {{16, 18, 49}};
  EXPECT_FALSE(solution_.canFormArray(arr, pieces));
}

TEST_P(CheckArrayFormationThroughConcatenationTest, Example3) {
  std::vector<int> arr = {91, 4, 64, 78};
  std::vector<std::vector<int>> pieces = {{78}, {4, 64}, {91}};
  EXPECT_TRUE(solution_.canFormArray(arr, pieces));
}

TEST_P(CheckArrayFormationThroughConcatenationTest, SelfAuthoredSinglePieceMismatchOrder) {
  std::vector<int> arr = {1, 2, 3, 4};
  std::vector<std::vector<int>> pieces = {{2, 1}, {3, 4}};
  EXPECT_FALSE(solution_.canFormArray(arr, pieces));
}

TEST_P(CheckArrayFormationThroughConcatenationTest, SelfAuthoredSingleElementPieces) {
  std::vector<int> arr = {5, 1, 3};
  std::vector<std::vector<int>> pieces = {{1}, {3}, {5}};
  EXPECT_TRUE(solution_.canFormArray(arr, pieces));
}

INSTANTIATE_TEST_SUITE_P(
    CheckArrayFormationThroughConcatenationTestCases,
    CheckArrayFormationThroughConcatenationTest,
    ::testing::ValuesIn(
        CheckArrayFormationThroughConcatenationSolution().getStrategyNames()));

}  // namespace leetcode::problem_1640
