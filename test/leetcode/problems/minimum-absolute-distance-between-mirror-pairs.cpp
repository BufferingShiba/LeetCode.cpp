#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/minimum-absolute-distance-between-mirror-pairs.h"

namespace leetcode {
namespace problem_3761 {

class MinimumAbsoluteDistanceBetweenMirrorPairsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution_.setStrategy(GetParam());
  }

  MinimumAbsoluteDistanceBetweenMirrorPairsSolution solution_;
};

TEST_P(MinimumAbsoluteDistanceBetweenMirrorPairsTest, Example1) {
  std::vector<int> nums = {12, 21, 45, 33, 54};
  EXPECT_EQ(1, solution_.minMirrorPairDistance(nums));
}

TEST_P(MinimumAbsoluteDistanceBetweenMirrorPairsTest, Example2) {
  std::vector<int> nums = {120, 21};
  EXPECT_EQ(1, solution_.minMirrorPairDistance(nums));
}

TEST_P(MinimumAbsoluteDistanceBetweenMirrorPairsTest, Example3) {
  std::vector<int> nums = {21, 120};
  EXPECT_EQ(-1, solution_.minMirrorPairDistance(nums));
}

TEST_P(MinimumAbsoluteDistanceBetweenMirrorPairsTest, SelfAuthoredSingleElement) {
  std::vector<int> nums = {5};
  EXPECT_EQ(-1, solution_.minMirrorPairDistance(nums));
}

TEST_P(MinimumAbsoluteDistanceBetweenMirrorPairsTest, SelfAuthoredSelfReverseDistant) {
  // 33 自身反转仍为 33：镜像对 (0,1) 与 (0,2)。
  // reverse(33)=33，所以 j=2 处 target=33 出现在 i=0，距离 2；
  // j=1 处 target=33 出现在 i=0，距离 1。因此 ans=1。
  std::vector<int> nums = {33, 33, 33};
  EXPECT_EQ(1, solution_.minMirrorPairDistance(nums));
}

INSTANTIATE_TEST_SUITE_P(
    MinimumAbsoluteDistanceBetweenMirrorPairsTest,
    MinimumAbsoluteDistanceBetweenMirrorPairsTest,
    ::testing::ValuesIn(
        MinimumAbsoluteDistanceBetweenMirrorPairsSolution().getStrategyNames()));

}  // namespace problem_3761
}  // namespace leetcode
