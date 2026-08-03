#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/minimum-number-of-flips-to-convert-binary-matrix-to-zero-matrix.h"

namespace leetcode::problem_1284 {

namespace {
using Solution = MinimumNumberOfFlipsToConvertBinaryMatrixToZeroMatrixSolution;
}

class MinimumNumberOfFlipsToConvertBinaryMatrixToZeroMatrixTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  Solution solution;
};

TEST_P(MinimumNumberOfFlipsToConvertBinaryMatrixToZeroMatrixTest, Example1) {
  std::vector<std::vector<int>> mat{{0, 0}, {0, 1}};
  EXPECT_EQ(solution.minFlips(mat), 3);
}

TEST_P(MinimumNumberOfFlipsToConvertBinaryMatrixToZeroMatrixTest, Example2) {
  std::vector<std::vector<int>> mat{{0}};
  EXPECT_EQ(solution.minFlips(mat), 0);
}

TEST_P(MinimumNumberOfFlipsToConvertBinaryMatrixToZeroMatrixTest, Example3) {
  std::vector<std::vector<int>> mat{{1, 0, 0}, {1, 0, 0}};
  EXPECT_EQ(solution.minFlips(mat), -1);
}

TEST_P(MinimumNumberOfFlipsToConvertBinaryMatrixToZeroMatrixTest, SelfAuthoredSingleOne) {
  std::vector<std::vector<int>> mat{{1}};
  EXPECT_EQ(solution.minFlips(mat), 1);
}

TEST_P(MinimumNumberOfFlipsToConvertBinaryMatrixToZeroMatrixTest, SelfAuthoredAllOnes2x2) {
  std::vector<std::vector<int>> mat{{1, 1}, {1, 1}};
  EXPECT_EQ(solution.minFlips(mat), 4);
}

INSTANTIATE_TEST_SUITE_P(
    MinimumNumberOfFlipsToConvertBinaryMatrixToZeroMatrixTestSuite,
    MinimumNumberOfFlipsToConvertBinaryMatrixToZeroMatrixTest,
    ::testing::ValuesIn(Solution().getStrategyNames()));

}  // namespace leetcode::problem_1284
