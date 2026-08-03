#include "leetcode/problems/count-submatrices-with-top-left-element-and-sum-less-than-k.h"

#include <gtest/gtest.h>

#include <string>
#include <vector>

namespace leetcode {
namespace problem_3070 {

class CountSubmatricesWithTopLeftElementAndSumLessThanKTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  CountSubmatricesWithTopLeftElementAndSumLessThanKSolution solution;
};

TEST_P(CountSubmatricesWithTopLeftElementAndSumLessThanKTest, Example1) {
  std::vector<std::vector<int>> grid = {{7, 6, 3}, {6, 6, 1}};
  int k = 18;
  EXPECT_EQ(solution.countSubmatrices(grid, k), 4);
}

TEST_P(CountSubmatricesWithTopLeftElementAndSumLessThanKTest, Example2) {
  std::vector<std::vector<int>> grid = {{7, 2, 9}, {1, 5, 0}, {2, 6, 6}};
  int k = 20;
  EXPECT_EQ(solution.countSubmatrices(grid, k), 6);
}

TEST_P(CountSubmatricesWithTopLeftElementAndSumLessThanKTest, SelfAuthoredSingleCell) {
  std::vector<std::vector<int>> grid = {{7}};
  EXPECT_EQ(solution.countSubmatrices(grid, 7), 1);
  EXPECT_EQ(solution.countSubmatrices(grid, 6), 0);
}

TEST_P(CountSubmatricesWithTopLeftElementAndSumLessThanKTest, SelfAuthoredSingleRow) {
  std::vector<std::vector<int>> grid = {{1, 2, 3, 4}};
  int k = 6;
  // prefix sums: 1, 3, 6, 10 -> those <=6: 1,3,6 => 3
  EXPECT_EQ(solution.countSubmatrices(grid, k), 3);
}

TEST_P(CountSubmatricesWithTopLeftElementAndSumLessThanKTest, SelfAuthoredSingleColumn) {
  std::vector<std::vector<int>> grid = {{1}, {2}, {3}, {4}};
  int k = 6;
  // prefix sums: 1, 3, 6, 10 -> 3
  EXPECT_EQ(solution.countSubmatrices(grid, k), 3);
}

INSTANTIATE_TEST_SUITE_P(
    CountSubmatricesWithTopLeftElementAndSumLessThanKTestSuite,
    CountSubmatricesWithTopLeftElementAndSumLessThanKTest,
    ::testing::ValuesIn(CountSubmatricesWithTopLeftElementAndSumLessThanKSolution()
                            .getStrategyNames()));

}  // namespace problem_3070
}  // namespace leetcode
