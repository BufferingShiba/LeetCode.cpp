#include <gtest/gtest.h>

#include <vector>

#include "leetcode/problems/count-substrings-that-satisfy-k-constraint-ii.h"

namespace leetcode::problem_3261 {

namespace {

std::vector<long long> RunSolution(
    const std::string& strategy, std::string s, int k,
    std::vector<std::vector<int>> queries) {
  CountSubstringsThatSatisfyKConstraintIiSolution solution;
  solution.setStrategy(strategy);
  return solution.countKConstraintSubstrings(std::move(s), k, queries);
}

}  // namespace

class CountSubstringsThatSatisfyKConstraintIiTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { strategy_ = GetParam(); }

  std::string strategy_;
};

TEST_P(CountSubstringsThatSatisfyKConstraintIiTest, Example1) {
  auto result = RunSolution(strategy_, "0001111", 2, {{0, 6}});
  EXPECT_EQ(result, std::vector<long long>({26}));
}

TEST_P(CountSubstringsThatSatisfyKConstraintIiTest, Example2) {
  auto result = RunSolution(strategy_, "010101", 1, {{0, 5}, {1, 4}, {2, 3}});
  EXPECT_EQ(result, std::vector<long long>({15, 9, 3}));
}

INSTANTIATE_TEST_SUITE_P(
    CountSubstringsThatSatisfyKConstraintIiTestSuite,
    CountSubstringsThatSatisfyKConstraintIiTest,
    ::testing::ValuesIn(
        CountSubstringsThatSatisfyKConstraintIiSolution().getStrategyNames()));

}  // namespace leetcode::problem_3261
