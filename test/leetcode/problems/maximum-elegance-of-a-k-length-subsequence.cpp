#include <gtest/gtest.h>

#include "leetcode/problems/maximum-elegance-of-a-k-length-subsequence.h"

#include <string>
#include <vector>

using namespace leetcode::problem_2813;

namespace {

struct TestCase {
  std::vector<std::vector<int>> items;
  int k;
  long long expected;
};

}  // namespace

class MaximumEleganceOfAKLengthSubsequenceTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }
  MaximumEleganceOfAKLengthSubsequenceSolution solution;
};

TEST_P(MaximumEleganceOfAKLengthSubsequenceTest, Examples) {
  std::vector<TestCase> cases = {
      {{{3, 2}, {5, 1}, {10, 1}}, 2, 17},
      {{{3, 1}, {3, 1}, {2, 2}, {5, 3}}, 3, 19},
      {{{1, 1}, {2, 1}, {3, 1}}, 3, 7},
  };
  for (auto& c : cases) {
    auto items = c.items;
    EXPECT_EQ(solution.findMaximumElegance(items, c.k), c.expected);
  }
}

TEST_P(MaximumEleganceOfAKLengthSubsequenceTest, SingleElement) {
  auto items = std::vector<std::vector<int>>{{7, 1}};
  EXPECT_EQ(solution.findMaximumElegance(items, 1), 8);  // 7 + 1^2
}

TEST_P(MaximumEleganceOfAKLengthSubsequenceTest, AllSameCategory) {
  // All items share one category; distinct stays 1, pick the two largest.
  auto items = std::vector<std::vector<int>>{{1, 1}, {2, 1}, {3, 1}, {4, 1}};
  EXPECT_EQ(solution.findMaximumElegance(items, 2), 8);  // (4 + 3) + 1^2
}

TEST_P(MaximumEleganceOfAKLengthSubsequenceTest, DistinctBoost) {
  // Profit prefers duplicate big item, but introducing a new category wins.
  // items: cat1 has 100, cat2 has 99, cat3 has 1. k=2.
  // Choose 100(cat1)+99(cat2): profit=199, distinct=2 -> 199+4=203.
  auto items = std::vector<std::vector<int>>{{100, 1}, {99, 2}, {1, 3}};
  EXPECT_EQ(solution.findMaximumElegance(items, 2), 203);
}

INSTANTIATE_TEST_SUITE_P(
    MaximumEleganceOfAKLengthSubsequence,
    MaximumEleganceOfAKLengthSubsequenceTest,
    ::testing::ValuesIn(
        MaximumEleganceOfAKLengthSubsequenceSolution().getStrategyNames()));
