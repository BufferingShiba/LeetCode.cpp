#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/largest-number-at-least-twice-of-others.h"

namespace leetcode {
namespace problem_747 {

class LargestNumberAtLeastTwiceOfOthersTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  LargestNumberAtLeastTwiceOfOthersSolution solution;
};

TEST_P(LargestNumberAtLeastTwiceOfOthersTest, Example1) {
  std::vector<int> nums = {3, 6, 1, 0};
  EXPECT_EQ(1, solution.dominantIndex(nums));
}

TEST_P(LargestNumberAtLeastTwiceOfOthersTest, Example2) {
  std::vector<int> nums = {1, 2, 3, 4};
  EXPECT_EQ(-1, solution.dominantIndex(nums));
}

TEST_P(LargestNumberAtLeastTwiceOfOthersTest, SelfAuthoredDominantWithZero) {
  std::vector<int> nums = {1, 3, 0};
  EXPECT_EQ(1, solution.dominantIndex(nums));
}

TEST_P(LargestNumberAtLeastTwiceOfOthersTest, SelfAuthoredMaxIsZero) {
  std::vector<int> nums = {0, 0};
  // max = 0, second max = 0, 0 >= 2*0 holds, so return index 0
  EXPECT_EQ(0, solution.dominantIndex(nums));
}

INSTANTIATE_TEST_SUITE_P(
    LargestNumberAtLeastTwiceOfOthersTestSuite,
    LargestNumberAtLeastTwiceOfOthersTest,
    ::testing::ValuesIn(LargestNumberAtLeastTwiceOfOthersSolution().getStrategyNames()));

}  // namespace problem_747
}  // namespace leetcode
