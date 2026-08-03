#include <gtest/gtest.h>

#include "leetcode/problems/increment-submatrices-by-one.h"

namespace leetcode {
namespace problem_2536 {

class IncrementSubmatricesByOneTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  IncrementSubmatricesByOneSolution solution_;
};

TEST_P(IncrementSubmatricesByOneTest, Example1) {
  int n = 3;
  std::vector<std::vector<int>> queries = {{1, 1, 2, 2}, {0, 0, 1, 1}};
  std::vector<std::vector<int>> expected = {{1, 1, 0}, {1, 2, 1}, {0, 1, 1}};
  EXPECT_EQ(solution_.rangeAddQueries(n, queries), expected);
}

TEST_P(IncrementSubmatricesByOneTest, Example2) {
  int n = 2;
  std::vector<std::vector<int>> queries = {{0, 0, 1, 1}};
  std::vector<std::vector<int>> expected = {{1, 1}, {1, 1}};
  EXPECT_EQ(solution_.rangeAddQueries(n, queries), expected);
}

TEST_P(IncrementSubmatricesByOneTest, SelfAuthoredSingleCell) {
  int n = 3;
  std::vector<std::vector<int>> queries = {{0, 0, 0, 0}, {1, 1, 1, 1}, {2, 2, 2, 2}};
  std::vector<std::vector<int>> expected = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
  EXPECT_EQ(solution_.rangeAddQueries(n, queries), expected);
}

TEST_P(IncrementSubmatricesByOneTest, SelfAuthoredFullOverlap) {
  int n = 2;
  std::vector<std::vector<int>> queries = {{0, 0, 1, 1}, {0, 0, 1, 1}, {0, 0, 1, 1}};
  std::vector<std::vector<int>> expected = {{3, 3}, {3, 3}};
  EXPECT_EQ(solution_.rangeAddQueries(n, queries), expected);
}

TEST_P(IncrementSubmatricesByOneTest, SelfAuthoredEdgeRow) {
  int n = 3;
  std::vector<std::vector<int>> queries = {{0, 0, 0, 2}};
  std::vector<std::vector<int>> expected = {{1, 1, 1}, {0, 0, 0}, {0, 0, 0}};
  EXPECT_EQ(solution_.rangeAddQueries(n, queries), expected);
}

TEST_P(IncrementSubmatricesByOneTest, SelfAuthoredNEqualsOne) {
  int n = 1;
  std::vector<std::vector<int>> queries = {{0, 0, 0, 0}};
  std::vector<std::vector<int>> expected = {{1}};
  EXPECT_EQ(solution_.rangeAddQueries(n, queries), expected);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    IncrementSubmatricesByOneTest,
    ::testing::ValuesIn(IncrementSubmatricesByOneSolution().getStrategyNames()));

}  // namespace problem_2536
}  // namespace leetcode
