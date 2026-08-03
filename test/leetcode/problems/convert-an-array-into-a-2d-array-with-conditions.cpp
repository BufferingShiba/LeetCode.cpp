#include <gtest/gtest.h>

#include "leetcode/problems/convert-an-array-into-a-2d-array-with-conditions.h"

namespace leetcode::problem_2610 {

class ConvertAnArrayIntoA2dArrayWithConditionsTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  ConvertAnArrayIntoA2dArrayWithConditionsSolution solution_;
};

TEST_P(ConvertAnArrayIntoA2dArrayWithConditionsTest, Example1) {
  std::vector<int> nums = {1, 3, 4, 1, 2, 3, 1};
  auto result = solution_.findMatrix(nums);

  // Verify that the total number of elements is preserved
  int total = 0;
  for (const auto& row : result) {
    total += static_cast<int>(row.size());
  }
  EXPECT_EQ(total, static_cast<int>(nums.size()));

  // Verify each row has distinct elements
  for (const auto& row : result) {
    std::unordered_set<int> seen(row.begin(), row.end());
    EXPECT_EQ(seen.size(), row.size());
  }

  // Verify minimal rows: max frequency of any element
  std::unordered_map<int, int> freq;
  for (int x : nums) freq[x]++;
  int maxFreq = 0;
  for (auto& [k, v] : freq) maxFreq = std::max(maxFreq, v);
  EXPECT_EQ(static_cast<int>(result.size()), maxFreq);
}

TEST_P(ConvertAnArrayIntoA2dArrayWithConditionsTest, Example2) {
  std::vector<int> nums = {1, 2, 3, 4};
  auto result = solution_.findMatrix(nums);

  int total = 0;
  for (const auto& row : result) {
    total += static_cast<int>(row.size());
  }
  EXPECT_EQ(total, static_cast<int>(nums.size()));

  for (const auto& row : result) {
    std::unordered_set<int> seen(row.begin(), row.end());
    EXPECT_EQ(seen.size(), row.size());
  }

  std::unordered_map<int, int> freq;
  for (int x : nums) freq[x]++;
  int maxFreq = 0;
  for (auto& [k, v] : freq) maxFreq = std::max(maxFreq, v);
  EXPECT_EQ(static_cast<int>(result.size()), maxFreq);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    ConvertAnArrayIntoA2dArrayWithConditionsTest,
    testing::ValuesIn(
        ConvertAnArrayIntoA2dArrayWithConditionsSolution().getStrategyNames()));

}  // namespace leetcode::problem_2610
