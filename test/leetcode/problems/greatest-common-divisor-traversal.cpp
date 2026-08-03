#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/greatest-common-divisor-traversal.h"

namespace leetcode {
namespace problem_2709 {
namespace {

class GreatestCommonDivisorTraversalTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  GreatestCommonDivisorTraversalSolution solution;
};

TEST_P(GreatestCommonDivisorTraversalTest, Example1) {
  std::vector<int> nums{2, 3, 6};
  EXPECT_TRUE(solution.canTraverseAllPairs(nums));
}

TEST_P(GreatestCommonDivisorTraversalTest, Example2) {
  std::vector<int> nums{3, 9, 5};
  EXPECT_FALSE(solution.canTraverseAllPairs(nums));
}

TEST_P(GreatestCommonDivisorTraversalTest, Example3) {
  std::vector<int> nums{4, 3, 12, 8};
  EXPECT_TRUE(solution.canTraverseAllPairs(nums));
}

TEST_P(GreatestCommonDivisorTraversalTest, SelfAuthoredSingleElement) {
  std::vector<int> nums{1};
  EXPECT_TRUE(solution.canTraverseAllPairs(nums));
}

TEST_P(GreatestCommonDivisorTraversalTest, SelfAuthoredAllOnes) {
  std::vector<int> nums{1, 1, 1};
  EXPECT_FALSE(solution.canTraverseAllPairs(nums));
}

TEST_P(GreatestCommonDivisorTraversalTest, SelfAuthoredPrimeAndOne) {
  std::vector<int> nums{1, 7};
  EXPECT_FALSE(solution.canTraverseAllPairs(nums));
}

TEST_P(GreatestCommonDivisorTraversalTest, SelfAuthoredAllSharePrime) {
  std::vector<int> nums{2, 4, 8, 16};
  EXPECT_TRUE(solution.canTraverseAllPairs(nums));
}

INSTANTIATE_TEST_SUITE_P(
    GreatestCommonDivisorTraversalTestSuite,
    GreatestCommonDivisorTraversalTest,
    ::testing::ValuesIn(
        GreatestCommonDivisorTraversalSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_2709
}  // namespace leetcode
