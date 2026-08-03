#include "leetcode/problems/number-of-excellent-pairs.h"

#include <gtest/gtest.h>
#include <string>

namespace leetcode {
namespace problem_2354 {
namespace {

class NumberOfExcellentPairsTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  NumberOfExcellentPairsSolution solution_;
};

TEST_P(NumberOfExcellentPairsTest, Example1) {
  std::vector<int> nums = {1, 2, 3, 1};
  int k = 3;
  EXPECT_EQ(5, solution_.countExcellentPairs(nums, k));
}

TEST_P(NumberOfExcellentPairsTest, Example2) {
  std::vector<int> nums = {5, 1, 1};
  int k = 10;
  EXPECT_EQ(0, solution_.countExcellentPairs(nums, k));
}

TEST_P(NumberOfExcellentPairsTest, SelfAuthoredSelfPairWithSingleElement) {
  std::vector<int> nums = {7};  // popcount(7) = 3
  int k = 6;                    // 3 + 3 == 6
  EXPECT_EQ(1, solution_.countExcellentPairs(nums, k));
}

TEST_P(NumberOfExcellentPairsTest, SelfAuthoredSelfPairNotCountedWhenBelowK) {
  std::vector<int> nums = {1};  // popcount(1) = 1
  int k = 3;
  EXPECT_EQ(0, solution_.countExcellentPairs(nums, k));
}

INSTANTIATE_TEST_SUITE_P(
    NumberOfExcellentPairsTestSuite, NumberOfExcellentPairsTest,
    ::testing::ValuesIn(NumberOfExcellentPairsSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_2354
}  // namespace leetcode
