#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/range-product-queries-of-powers.h"

using leetcode::problem_2438::RangeProductQueriesOfPowersSolution;

namespace {

std::vector<int> ToVector(const std::vector<std::vector<int>>& queries) {
  // placeholder; not used. Kept for clarity.
  return {};
}

}  // namespace

class RangeProductQueriesOfPowersTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution.setStrategy(GetParam());
  }

  RangeProductQueriesOfPowersSolution solution;
};

TEST_P(RangeProductQueriesOfPowersTest, Example1) {
  int n = 15;
  std::vector<std::vector<int>> queries = {{0, 1}, {2, 2}, {0, 3}};
  std::vector<int> expected = {2, 4, 64};
  EXPECT_EQ(solution.productQueries(n, queries), expected);
}

TEST_P(RangeProductQueriesOfPowersTest, Example2) {
  int n = 2;
  std::vector<std::vector<int>> queries = {{0, 0}};
  std::vector<int> expected = {2};
  EXPECT_EQ(solution.productQueries(n, queries), expected);
}

TEST_P(RangeProductQueriesOfPowersTest, SelfAuthoredSinglePower) {
  // n = 8 (single power of 2): powers = [8]
  int n = 8;
  std::vector<std::vector<int>> queries = {{0, 0}};
  std::vector<int> expected = {8};
  EXPECT_EQ(solution.productQueries(n, queries), expected);
}

INSTANTIATE_TEST_SUITE_P(
    RangeProductQueriesOfPowers,
    RangeProductQueriesOfPowersTest,
    ::testing::ValuesIn(
        RangeProductQueriesOfPowersSolution().getStrategyNames()));
