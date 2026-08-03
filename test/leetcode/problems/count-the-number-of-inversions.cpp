#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/count-the-number-of-inversions.h"

namespace leetcode {
namespace problem_3193 {

class CountTheNumberOfInversionsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  CountTheNumberOfInversionsSolution solution;
};

TEST_P(CountTheNumberOfInversionsTest, Example1) {
  int n = 3;
  std::vector<std::vector<int>> requirements = {{2, 2}, {0, 0}};
  EXPECT_EQ(solution.numberOfPermutations(n, requirements), 2);
}

TEST_P(CountTheNumberOfInversionsTest, Example2) {
  int n = 3;
  std::vector<std::vector<int>> requirements = {{2, 2}, {1, 1}, {0, 0}};
  EXPECT_EQ(solution.numberOfPermutations(n, requirements), 1);
}

TEST_P(CountTheNumberOfInversionsTest, Example3) {
  int n = 2;
  std::vector<std::vector<int>> requirements = {{0, 0}, {1, 0}};
  EXPECT_EQ(solution.numberOfPermutations(n, requirements), 1);
}

TEST_P(CountTheNumberOfInversionsTest, SelfAuthoredOnlyLastRequirement) {
  int n = 3;
  std::vector<std::vector<int>> requirements = {{2, 0}};
  // Only permutation with 0 total inversions is [0,1,2] -> 1.
  EXPECT_EQ(solution.numberOfPermutations(n, requirements), 1);
}

INSTANTIATE_TEST_SUITE_P(
    CountTheNumberOfInversionsTestSuite, CountTheNumberOfInversionsTest,
    ::testing::ValuesIn(CountTheNumberOfInversionsSolution().getStrategyNames()));

}  // namespace problem_3193
}  // namespace leetcode
