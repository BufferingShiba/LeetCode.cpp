#include <gtest/gtest.h>

#include <algorithm>
#include <string>
#include <vector>

#include "leetcode/problems/beautiful-array.h"

namespace leetcode {
namespace problem_932 {
namespace {

bool isBeautiful(const std::vector<int>& nums) {
  int n = static_cast<int>(nums.size());
  // Check permutation of [1..n].
  std::vector<bool> seen(n + 1, false);
  for (int v : nums) {
    if (v < 1 || v > n || seen[v]) return false;
    seen[v] = true;
  }
  // Check no i<k<j with 2*nums[k] == nums[i] + nums[j].
  for (int i = 0; i < n; ++i) {
    for (int k = i + 1; k < n; ++k) {
      for (int j = k + 1; j < n; ++j) {
        if (2 * static_cast<long long>(nums[k]) ==
            static_cast<long long>(nums[i]) + nums[j]) {
          return false;
        }
      }
    }
  }
  return true;
}

}  // namespace

class BeautifulArrayTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  BeautifulArraySolution solution;
};

TEST_P(BeautifulArrayTest, Example1) {
  std::vector<int> result = solution.beautifulArray(4);
  EXPECT_TRUE(isBeautiful(result));
}

TEST_P(BeautifulArrayTest, Example2) {
  std::vector<int> result = solution.beautifulArray(5);
  EXPECT_TRUE(isBeautiful(result));
}

TEST_P(BeautifulArrayTest, SelfAuthoredSingleElement) {
  std::vector<int> result = solution.beautifulArray(1);
  EXPECT_TRUE(isBeautiful(result));
  EXPECT_EQ(result[0], 1);
}

TEST_P(BeautifulArrayTest, SelfAuthoredSmallN2) {
  std::vector<int> result = solution.beautifulArray(2);
  EXPECT_TRUE(isBeautiful(result));
}

TEST_P(BeautifulArrayTest, SelfAuthoredLargeBoundary) {
  std::vector<int> result = solution.beautifulArray(1000);
  EXPECT_TRUE(isBeautiful(result));
  EXPECT_EQ(static_cast<int>(result.size()), 1000);
}

INSTANTIATE_TEST_SUITE_P(
    BeautifulArrayTestSuite, BeautifulArrayTest,
    ::testing::ValuesIn(BeautifulArraySolution().getStrategyNames()));

}  // namespace problem_932
}  // namespace leetcode
