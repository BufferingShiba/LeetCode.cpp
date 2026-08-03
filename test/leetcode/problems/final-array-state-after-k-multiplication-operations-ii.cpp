#include <gtest/gtest.h>

#include "leetcode/problems/final-array-state-after-k-multiplication-operations-ii.h"

namespace leetcode {
namespace problem_3266 {

class FinalArrayStateAfterKMultiplicationOperationsIiTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }
  FinalArrayStateAfterKMultiplicationOperationsIiSolution solution_;
};

TEST_P(FinalArrayStateAfterKMultiplicationOperationsIiTest, Example1) {
  std::vector<int> nums = {2, 1, 3, 5, 6};
  int k = 5;
  int multiplier = 2;
  std::vector<int> expected = {8, 4, 6, 5, 6};
  EXPECT_EQ(solution_.getFinalState(nums, k, multiplier), expected);
}

TEST_P(FinalArrayStateAfterKMultiplicationOperationsIiTest, Example2) {
  std::vector<int> nums = {100000, 2000};
  int k = 2;
  int multiplier = 1000000;
  std::vector<int> expected = {999999307, 999999993};
  EXPECT_EQ(solution_.getFinalState(nums, k, multiplier), expected);
}

TEST_P(FinalArrayStateAfterKMultiplicationOperationsIiTest, SelfAuthoredSingleElement) {
  std::vector<int> nums = {5};
  int k = 10;
  int multiplier = 3;
  // 5 * 3^10 = 5 * 59049 = 295245; 295245 % 1000000007 = 295245
  std::vector<int> expected = {295245};
  EXPECT_EQ(solution_.getFinalState(nums, k, multiplier), expected);
}

TEST_P(FinalArrayStateAfterKMultiplicationOperationsIiTest, SelfAuthoredMultiplierOne) {
  std::vector<int> nums = {100, 200, 300};
  int k = 1000000000;
  int multiplier = 1;
  std::vector<int> expected = {100, 200, 300};
  EXPECT_EQ(solution_.getFinalState(nums, k, multiplier), expected);
}

TEST_P(FinalArrayStateAfterKMultiplicationOperationsIiTest, SelfAuthoredAllEqualValues) {
  std::vector<int> nums = {2, 2, 2};
  int k = 5;
  int multiplier = 2;
  // Op1: idx0 2→4 [4,2,2]; Op2: idx1 2→4 [4,4,2]; Op3: idx2 2→4 [4,4,4]
  // Op4: idx0 4→8 [8,4,4]; Op5: idx1 4→8 [8,8,4]
  std::vector<int> expected = {8, 8, 4};
  EXPECT_EQ(solution_.getFinalState(nums, k, multiplier), expected);
}

TEST_P(FinalArrayStateAfterKMultiplicationOperationsIiTest, SelfAuthoredLargeKSmallMultiplier) {
  std::vector<int> nums = {1, 2, 3};
  int k = 100;
  int multiplier = 2;
  // Just verify no crash and size matches
  auto result = solution_.getFinalState(nums, k, multiplier);
  EXPECT_EQ(result.size(), 3u);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    FinalArrayStateAfterKMultiplicationOperationsIiTest,
    testing::ValuesIn(
        FinalArrayStateAfterKMultiplicationOperationsIiSolution().getStrategyNames()));

}  // namespace problem_3266
}  // namespace leetcode
