#include <gtest/gtest.h>
#include "leetcode/problems/prime-in-diagonal.h"

namespace leetcode {
namespace problem_2614 {

class PrimeInDiagonalTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  PrimeInDiagonalSolution solution;
};

TEST_P(PrimeInDiagonalTest, Example1) {
  std::vector<std::vector<int>> nums = {{1, 2, 3}, {5, 6, 7}, {9, 10, 11}};
  EXPECT_EQ(11, solution.diagonalPrime(nums));
}

TEST_P(PrimeInDiagonalTest, Example2) {
  std::vector<std::vector<int>> nums = {{1, 2, 3}, {5, 17, 7}, {9, 11, 10}};
  EXPECT_EQ(17, solution.diagonalPrime(nums));
}

TEST_P(PrimeInDiagonalTest, SelfAuthoredNoPrimeOnDiagonal) {
  std::vector<std::vector<int>> nums = {{1, 1}, {1, 1}};
  EXPECT_EQ(0, solution.diagonalPrime(nums));
}

TEST_P(PrimeInDiagonalTest, SelfAuthoredSingleElement) {
  std::vector<std::vector<int>> nums = {{7}};
  EXPECT_EQ(7, solution.diagonalPrime(nums));
}

INSTANTIATE_TEST_SUITE_P(
    PrimeInDiagonalTestSuite, PrimeInDiagonalTest,
    ::testing::ValuesIn(PrimeInDiagonalSolution().getStrategyNames()));

}  // namespace problem_2614
}  // namespace leetcode
