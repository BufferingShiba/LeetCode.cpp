#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/valid-binary-strings-with-cost-limit.h"

namespace leetcode {
namespace problem_3955 {
namespace {

bool isValid(const std::string& s, int k) {
  int cost = 0;
  for (int i = 0; i < static_cast<int>(s.size()); ++i) {
    if (s[i] == '1') {
      if (i > 0 && s[i - 1] == '1') return false;
      cost += i;
    }
  }
  return cost <= k;
}

}  // namespace

class ValidBinaryStringsWithCostLimitTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  ValidBinaryStringsWithCostLimit solution;
};

TEST_P(ValidBinaryStringsWithCostLimitTest, Example1) {
  auto result = solution.generateValidStrings(3, 1);
  std::vector<std::string> expected = {"000", "010", "100"};
  ASSERT_EQ(result.size(), expected.size());
  for (const auto& s : expected) {
    EXPECT_NE(std::find(result.begin(), result.end(), s), result.end());
  }
}

TEST_P(ValidBinaryStringsWithCostLimitTest, Example2) {
  auto result = solution.generateValidStrings(1, 0);
  ASSERT_EQ(result.size(), 2u);
  EXPECT_NE(std::find(result.begin(), result.end(), "0"), result.end());
  EXPECT_NE(std::find(result.begin(), result.end(), "1"), result.end());
}

TEST_P(ValidBinaryStringsWithCostLimitTest, SelfAuthoredAllGeneratedAreValidAndComplete) {
  int n = 6;
  int k = 8;
  auto result = solution.generateValidStrings(n, k);

  // Every generated string is valid.
  for (const auto& s : result) {
    ASSERT_EQ(s.size(), static_cast<size_t>(n));
    ASSERT_TRUE(isValid(s, k));
  }

  // Every valid string of length n is present (completeness), n=6 small so brute force.
  for (int mask = 0; mask < (1 << n); ++mask) {
    std::string s;
    for (int i = 0; i < n; ++i) {
      s.push_back(((mask >> i) & 1) ? '1' : '0');
    }
    if (isValid(s, k)) {
      EXPECT_NE(std::find(result.begin(), result.end(), s), result.end());
    }
  }
}

INSTANTIATE_TEST_SUITE_P(
    ValidBinaryStringsWithCostLimitTestSuite,
    ValidBinaryStringsWithCostLimitTest,
    ::testing::ValuesIn(ValidBinaryStringsWithCostLimit().getStrategyNames()));

}  // namespace problem_3955
}  // namespace leetcode
