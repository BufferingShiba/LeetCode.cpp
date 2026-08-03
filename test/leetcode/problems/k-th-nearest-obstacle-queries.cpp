#include <gtest/gtest.h>
#include "leetcode/problems/k-th-nearest-obstacle-queries.h"

#include <vector>

using namespace leetcode::problem_3275;

class KThNearestObstacleQueriesTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  KThNearestObstacleQueriesSolution solution_;
};

TEST_P(KThNearestObstacleQueriesTest, Example1) {
  std::vector<std::vector<int>> queries = {{1, 2}, {3, 4}, {2, 3}, {-3, 0}};
  int k = 2;
  std::vector<int> expected = {-1, 7, 5, 3};
  EXPECT_EQ(solution_.resultsArray(queries, k), expected);
}

TEST_P(KThNearestObstacleQueriesTest, Example2) {
  std::vector<std::vector<int>> queries = {{5, 5}, {4, 4}, {3, 3}};
  int k = 1;
  std::vector<int> expected = {10, 8, 6};
  EXPECT_EQ(solution_.resultsArray(queries, k), expected);
}

INSTANTIATE_TEST_SUITE_P(
    AllStrategies, KThNearestObstacleQueriesTest,
    ::testing::ValuesIn(KThNearestObstacleQueriesSolution().getStrategyNames()));
