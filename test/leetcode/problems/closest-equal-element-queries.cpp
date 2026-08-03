#include "leetcode/problems/closest-equal-element-queries.h"

#include <gtest/gtest.h>

namespace leetcode {
namespace problem_3488 {
namespace {

class ClosestEqualElementQueriesTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  ClosestEqualElementQueriesSolution solution_;
};

TEST_P(ClosestEqualElementQueriesTest, Example1) {
  std::vector<int> nums = {1, 3, 1, 4, 1, 3, 2};
  std::vector<int> queries = {0, 3, 5};
  std::vector<int> expected = {2, -1, 3};
  EXPECT_EQ(solution_.solveQueries(nums, queries), expected);
}

TEST_P(ClosestEqualElementQueriesTest, Example2) {
  std::vector<int> nums = {1, 2, 3, 4};
  std::vector<int> queries = {0, 1, 2, 3};
  std::vector<int> expected = {-1, -1, -1, -1};
  EXPECT_EQ(solution_.solveQueries(nums, queries), expected);
}

TEST_P(ClosestEqualElementQueriesTest, SelfAuthoredQueryEveryIndex) {
  std::vector<int> nums = {1, 3, 1, 4, 1, 3, 2};
  std::vector<int> queries = {0, 1, 2, 3, 4, 5, 6};
  // value 1 at indices {0,2,4}: dist[0]=min(2,4->0 circ=3)=2,
  // dist[2]=2, dist[4]=2
  // value 3 at indices {1,5}: dist[1]=min(4, circ:1+7-5=3)=3,
  // dist[5]=3
  // value 4 at {3}, value 2 at {6}: single -> -1
  std::vector<int> expected = {2, 3, 2, -1, 2, 3, -1};
  EXPECT_EQ(solution_.solveQueries(nums, queries), expected);
}

TEST_P(ClosestEqualElementQueriesTest, SelfAuthoredSameValueAllArray) {
  std::vector<int> nums = {5, 5, 5, 5, 5};
  std::vector<int> queries = {0, 1, 2, 3, 4};
  // all values 5, every distance is 1
  std::vector<int> expected = {1, 1, 1, 1, 1};
  EXPECT_EQ(solution_.solveQueries(nums, queries), expected);
}

INSTANTIATE_TEST_SUITE_P(
    ClosestEqualElementQueriesTestSuite, ClosestEqualElementQueriesTest,
    ::testing::ValuesIn(
        ClosestEqualElementQueriesSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_3488
}  // namespace leetcode
