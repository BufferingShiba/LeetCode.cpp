#include <gtest/gtest.h>
#include "leetcode/problems/concatenation-of-array.h"

namespace leetcode::problem_1929 {

class ConcatenationOfArrayTest : public ::testing::TestWithParam<std::string> {
 protected:
  ConcatenationOfArraySolution solution;
  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(ConcatenationOfArrayTest, Example1) {
  std::vector<int> nums = {1, 2, 1};
  std::vector<int> expected = {1, 2, 1, 1, 2, 1};
  EXPECT_EQ(solution.getConcatenation(nums), expected);
}

TEST_P(ConcatenationOfArrayTest, Example2) {
  std::vector<int> nums = {1, 3, 2, 1};
  std::vector<int> expected = {1, 3, 2, 1, 1, 3, 2, 1};
  EXPECT_EQ(solution.getConcatenation(nums), expected);
}

INSTANTIATE_TEST_SUITE_P(ConcatenationOfArray, ConcatenationOfArrayTest,
                         ::testing::ValuesIn(ConcatenationOfArraySolution()
                                                 .getStrategyNames()));

}  // namespace leetcode::problem_1929
