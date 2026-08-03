#include <gtest/gtest.h>

#include <numeric>
#include <set>
#include <string>
#include <vector>

#include "leetcode/problems/find-n-unique-integers-sum-up-to-zero.h"

namespace leetcode {
namespace problem_1304 {

class FindNUniqueIntegersSumUpToZeroTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  FindNUniqueIntegersSumUpToZeroSolution solution;
};

static bool IsValid(const std::vector<int>& arr, int n) {
  if (static_cast<int>(arr.size()) != n) return false;
  std::set<int> seen(arr.begin(), arr.end());
  if (static_cast<int>(seen.size()) != n) return false;
  int sum = std::accumulate(arr.begin(), arr.end(), 0);
  return sum == 0;
}

TEST_P(FindNUniqueIntegersSumUpToZeroTest, Example1) {
  auto result = solution.sumZero(5);
  EXPECT_TRUE(IsValid(result, 5));
}

TEST_P(FindNUniqueIntegersSumUpToZeroTest, Example2) {
  auto result = solution.sumZero(3);
  EXPECT_TRUE(IsValid(result, 3));
}

TEST_P(FindNUniqueIntegersSumUpToZeroTest, Example3) {
  auto result = solution.sumZero(1);
  EXPECT_TRUE(IsValid(result, 1));
}

TEST_P(FindNUniqueIntegersSumUpToZeroTest, SelfAuthoredEdgeCaseEven) {
  auto result = solution.sumZero(2);
  EXPECT_TRUE(IsValid(result, 2));
}

TEST_P(FindNUniqueIntegersSumUpToZeroTest, SelfAuthoredEdgeCaseLarger) {
  auto result = solution.sumZero(1000);
  EXPECT_TRUE(IsValid(result, 1000));
}

INSTANTIATE_TEST_SUITE_P(
    FindNUniqueIntegersSumUpToZeroTestCases,
    FindNUniqueIntegersSumUpToZeroTest,
    ::testing::ValuesIn(FindNUniqueIntegersSumUpToZeroSolution().getStrategyNames()));

}  // namespace problem_1304
}  // namespace leetcode
