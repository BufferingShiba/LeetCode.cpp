#include <gtest/gtest.h>

#include "leetcode/problems/find-original-array-from-doubled-array.h"

namespace leetcode::problem_2007 {

class FindOriginalArrayFromDoubledArrayTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }
  FindOriginalArrayFromDoubledArraySolution solution_;
};

TEST_P(FindOriginalArrayFromDoubledArrayTest, Example1) {
  std::vector<int> changed = {1, 3, 4, 2, 6, 8};
  auto result = solution_.findOriginalArray(changed);
  ASSERT_EQ(result.size(), 3u);
  std::sort(result.begin(), result.end());
  EXPECT_EQ(result, (std::vector<int>{1, 3, 4}));
}

TEST_P(FindOriginalArrayFromDoubledArrayTest, Example2) {
  std::vector<int> changed = {6, 3, 0, 1};
  auto result = solution_.findOriginalArray(changed);
  EXPECT_TRUE(result.empty());
}

TEST_P(FindOriginalArrayFromDoubledArrayTest, Example3) {
  std::vector<int> changed = {1};
  auto result = solution_.findOriginalArray(changed);
  EXPECT_TRUE(result.empty());
}

TEST_P(FindOriginalArrayFromDoubledArrayTest, SelfAuthoredAllZeros) {
  std::vector<int> changed = {0, 0, 0, 0};
  auto result = solution_.findOriginalArray(changed);
  ASSERT_EQ(result.size(), 2u);
  EXPECT_EQ(result, (std::vector<int>{0, 0}));
}

TEST_P(FindOriginalArrayFromDoubledArrayTest, SelfAuthoredSinglePair) {
  std::vector<int> changed = {5, 10};
  auto result = solution_.findOriginalArray(changed);
  ASSERT_EQ(result.size(), 1u);
  EXPECT_EQ(result[0], 5);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    FindOriginalArrayFromDoubledArrayTest,
    testing::ValuesIn(
        FindOriginalArrayFromDoubledArraySolution().getStrategyNames()));

}  // namespace leetcode::problem_2007
