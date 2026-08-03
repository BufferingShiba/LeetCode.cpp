#include <gtest/gtest.h>

#include <vector>

#include "leetcode/problems/global-and-local-inversions.h"

namespace leetcode {
namespace problem_775 {
namespace {

class GlobalAndLocalInversionsTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  GlobalAndLocalInversionsSolution solution_;
};

TEST_P(GlobalAndLocalInversionsTest, Example1) {
  std::vector<int> nums = {1, 0, 2};
  EXPECT_TRUE(solution_.isIdealPermutation(nums));
}

TEST_P(GlobalAndLocalInversionsTest, Example2) {
  std::vector<int> nums = {1, 2, 0};
  EXPECT_FALSE(solution_.isIdealPermutation(nums));
}

TEST_P(GlobalAndLocalInversionsTest, SelfAuthoredSingleElement) {
  std::vector<int> nums = {0};
  EXPECT_TRUE(solution_.isIdealPermutation(nums));
}

TEST_P(GlobalAndLocalInversionsTest, SelfAuthoredAlreadySorted) {
  std::vector<int> nums = {0, 1, 2, 3, 4};
  EXPECT_TRUE(solution_.isIdealPermutation(nums));
}

TEST_P(GlobalAndLocalInversionsTest, SelfAuthoredReversedSmall) {
  // [1, 0] is ideal (single adjacent swap)
  std::vector<int> nums = {1, 0};
  EXPECT_TRUE(solution_.isIdealPermutation(nums));
}

TEST_P(GlobalAndLocalInversionsTest, SelfAuthoredReversedLarger) {
  // [3, 2, 1, 0] has |3-0|=3 > 1, not ideal
  std::vector<int> nums = {3, 2, 1, 0};
  EXPECT_FALSE(solution_.isIdealPermutation(nums));
}

TEST_P(GlobalAndLocalInversionsTest, SelfAuthoredNonLocalInversion) {
  // 2 is at index 0, should be at index 2, delta = 2
  std::vector<int> nums = {2, 0, 1};
  EXPECT_FALSE(solution_.isIdealPermutation(nums));
}

TEST_P(GlobalAndLocalInversionsTest, SelfAuthoredIdealWithMultipleSwaps) {
  // Adjacent swaps: [0,1,2,3] -> swap 1,2 -> [0,2,1,3] -> swap 2,3 -> [0,3,1,2]?
  // Let's just use a known ideal: [1,0,3,2]
  std::vector<int> nums = {1, 0, 3, 2};
  EXPECT_TRUE(solution_.isIdealPermutation(nums));
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    GlobalAndLocalInversionsTest,
    testing::ValuesIn(
        GlobalAndLocalInversionsSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_775
}  // namespace leetcode
