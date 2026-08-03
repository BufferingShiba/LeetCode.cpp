#include <gtest/gtest.h>

#include <vector>

#include "leetcode/problems/restore-the-array-from-adjacent-pairs.h"

namespace leetcode {
namespace problem_1743 {
namespace {

bool isValid(const std::vector<int>& nums,
             const std::vector<std::vector<int>>& adjacentPairs) {
  if (nums.size() != static_cast<size_t>(adjacentPairs.size() + 1)) return false;
  std::unordered_set<long long> seen;
  for (const auto& p : adjacentPairs) {
    long long key = (static_cast<long long>(p[0]) + 200001) * 200002 +
                    (static_cast<long long>(p[1]) + 200001);
    long long keyRev = (static_cast<long long>(p[1]) + 200001) * 200002 +
                       (static_cast<long long>(p[0]) + 200001);
    seen.insert(key);
    seen.insert(keyRev);
  }
  for (size_t i = 0; i + 1 < nums.size(); ++i) {
    long long key = (static_cast<long long>(nums[i]) + 200001) * 200002 +
                    (static_cast<long long>(nums[i + 1]) + 200001);
    if (seen.find(key) == seen.end()) return false;
  }
  return true;
}

}  // namespace

class RestoreTheArrayFromAdjacentPairsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  RestoreTheArrayFromAdjacentPairsSolution solution;
};

TEST_P(RestoreTheArrayFromAdjacentPairsTest, Example1) {
  std::vector<std::vector<int>> input = {{2, 1}, {3, 4}, {3, 2}};
  auto result = solution.restoreArray(input);
  EXPECT_TRUE(isValid(result, std::vector<std::vector<int>>{{2, 1}, {3, 4}, {3, 2}}));
}

TEST_P(RestoreTheArrayFromAdjacentPairsTest, Example2) {
  std::vector<std::vector<int>> input = {{4, -2}, {1, 4}, {-3, 1}};
  auto result = solution.restoreArray(input);
  EXPECT_TRUE(isValid(result, std::vector<std::vector<int>>{{4, -2}, {1, 4}, {-3, 1}}));
}

TEST_P(RestoreTheArrayFromAdjacentPairsTest, Example3) {
  std::vector<std::vector<int>> input = {{100000, -100000}};
  auto result = solution.restoreArray(input);
  EXPECT_TRUE(isValid(result, std::vector<std::vector<int>>{{100000, -100000}}));
}

INSTANTIATE_TEST_SUITE_P(
    RestoreTheArrayFromAdjacentPairsTestSuite,
    RestoreTheArrayFromAdjacentPairsTest,
    ::testing::ValuesIn(
        RestoreTheArrayFromAdjacentPairsSolution().getStrategyNames()));

}  // namespace problem_1743
}  // namespace leetcode
