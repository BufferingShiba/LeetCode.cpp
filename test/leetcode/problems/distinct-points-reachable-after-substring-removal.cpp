#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/distinct-points-reachable-after-substring-removal.h"

namespace leetcode {
namespace problem_3694 {
namespace {

class DistinctPointsReachableAfterSubstringRemovalTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  DistinctPointsReachableAfterSubstringRemovalSolution solution;
};

TEST_P(DistinctPointsReachableAfterSubstringRemovalTest, Example1) {
  EXPECT_EQ(solution.distinctPoints("LUL", 1), 2);
}

TEST_P(DistinctPointsReachableAfterSubstringRemovalTest, Example2) {
  EXPECT_EQ(solution.distinctPoints("UDLR", 4), 1);
}

TEST_P(DistinctPointsReachableAfterSubstringRemovalTest, Example3) {
  EXPECT_EQ(solution.distinctPoints("UU", 1), 1);
}

TEST_P(DistinctPointsReachableAfterSubstringRemovalTest, SelfAuthored) {
  // Remove either the first or the second 'R': window vectors both {1,0},
  // so only 1 distinct endpoint.
  EXPECT_EQ(solution.distinctPoints("RR", 1), 1);
  // Windows of length 2: "UD" -> {0,0}, "DL" -> {0,-1}+{-1,0}={-1,-1},
  // "LR" -> {0,0}. Distinct vectors: {0,0}, {-1,-1} => 2.
  EXPECT_EQ(solution.distinctPoints("UDLR", 2), 2);
}

INSTANTIATE_TEST_SUITE_P(
    DistinctPointsReachableAfterSubstringRemovalTests,
    DistinctPointsReachableAfterSubstringRemovalTest,
    ::testing::ValuesIn(
        DistinctPointsReachableAfterSubstringRemovalSolution()
            .getStrategyNames()));

}  // namespace
}  // namespace problem_3694
}  // namespace leetcode
