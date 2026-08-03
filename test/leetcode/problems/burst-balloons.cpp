#include <gtest/gtest.h>

#include "leetcode/problems/burst-balloons.h"

#include <string>
#include <vector>

namespace leetcode::problem_312 {

class BurstBalloonsTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  BurstBalloonsSolution solution_;
};

TEST_P(BurstBalloonsTest, Example1) {
  std::vector<int> nums{3, 1, 5, 8};
  EXPECT_EQ(167, solution_.maxCoins(nums));
}

TEST_P(BurstBalloonsTest, Example2) {
  std::vector<int> nums{1, 5};
  EXPECT_EQ(10, solution_.maxCoins(nums));
}

TEST_P(BurstBalloonsTest, SelfAuthoredSingleElement) {
  std::vector<int> nums{7};
  EXPECT_EQ(7, solution_.maxCoins(nums));
}

TEST_P(BurstBalloonsTest, SelfAuthoredAllZeros) {
  std::vector<int> nums{0, 0, 0};
  EXPECT_EQ(0, solution_.maxCoins(nums));
}

TEST_P(BurstBalloonsTest, SelfAuthoredTwoElements) {
  std::vector<int> nums{3, 4};
  // Burst 3 -> 1*3*4=12, then 4 -> 1*4*1=4, total 16.
  // Or burst 4 first: 3*4*1=12, then 3: 1*3*1=3, total 15. Max = 16.
  EXPECT_EQ(16, solution_.maxCoins(nums));
}

INSTANTIATE_TEST_SUITE_P(
    BurstBalloonsTestSuite, BurstBalloonsTest,
    ::testing::ValuesIn(BurstBalloonsSolution().getStrategyNames()));

}  // namespace leetcode::problem_312
