#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/queries-on-a-permutation-with-key.h"

namespace leetcode {
namespace problem_1409 {

class QueriesOnAPermutationWithKeyTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  QueriesOnAPermutationWithKeySolution solution;

  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(QueriesOnAPermutationWithKeyTest, Example1) {
  std::vector<int> queries = {3, 1, 2, 1};
  int m = 5;
  std::vector<int> expected = {2, 1, 2, 1};
  EXPECT_EQ(solution.processQueries(queries, m), expected);
}

TEST_P(QueriesOnAPermutationWithKeyTest, Example2) {
  std::vector<int> queries = {4, 1, 2, 2};
  int m = 4;
  std::vector<int> expected = {3, 1, 2, 0};
  EXPECT_EQ(solution.processQueries(queries, m), expected);
}

TEST_P(QueriesOnAPermutationWithKeyTest, Example3) {
  std::vector<int> queries = {7, 5, 5, 8, 3};
  int m = 8;
  std::vector<int> expected = {6, 5, 0, 7, 5};
  EXPECT_EQ(solution.processQueries(queries, m), expected);
}

TEST_P(QueriesOnAPermutationWithKeyTest, SelfAuthoredSingleElement) {
  std::vector<int> queries = {1};
  int m = 1;
  std::vector<int> expected = {0};
  EXPECT_EQ(solution.processQueries(queries, m), expected);
}

INSTANTIATE_TEST_SUITE_P(
    QueriesOnAPermutationWithKeyTestSuite,
    QueriesOnAPermutationWithKeyTest,
    ::testing::ValuesIn(QueriesOnAPermutationWithKeySolution().getStrategyNames()));

}  // namespace problem_1409
}  // namespace leetcode
