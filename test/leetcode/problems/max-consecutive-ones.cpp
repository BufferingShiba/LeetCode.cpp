#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/max-consecutive-ones.h"

namespace leetcode {
namespace problem_485 {

class MaxConsecutiveOnesTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MaxConsecutiveOnesSolution solution;
};

TEST_P(MaxConsecutiveOnesTest, Example1) {
  std::vector<int> nums = {1, 1, 0, 1, 1, 1};
  EXPECT_EQ(solution.findMaxConsecutiveOnes(nums), 3);
}

TEST_P(MaxConsecutiveOnesTest, Example2) {
  std::vector<int> nums = {1, 0, 1, 1, 0, 1};
  EXPECT_EQ(solution.findMaxConsecutiveOnes(nums), 2);
}

TEST_P(MaxConsecutiveOnesTest, SelfAuthoredAllOnes) {
  std::vector<int> nums = {1, 1, 1, 1};
  EXPECT_EQ(solution.findMaxConsecutiveOnes(nums), 4);
}

TEST_P(MaxConsecutiveOnesTest, SelfAuthoredNoOnes) {
  std::vector<int> nums = {0, 0, 0};
  EXPECT_EQ(solution.findMaxConsecutiveOnes(nums), 0);
}

TEST_P(MaxConsecutiveOnesTest, SelfAuthoredSingleOne) {
  std::vector<int> nums = {1};
  EXPECT_EQ(solution.findMaxConsecutiveOnes(nums), 1);
}

INSTANTIATE_TEST_SUITE_P(
    MaxConsecutiveOnesTestSuite, MaxConsecutiveOnesTest,
    ::testing::ValuesIn(MaxConsecutiveOnesSolution().getStrategyNames()));

}  // namespace problem_485
}  // namespace leetcode
