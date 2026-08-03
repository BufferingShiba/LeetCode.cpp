#include <string>
#include <vector>

#include <gtest/gtest.h>

#include "leetcode/problems/count-sequences-to-k.h"

namespace leetcode {
namespace problem_3850 {

class CountSequencesToKTest : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  CountSequencesToKSolution solution;
};

TEST_P(CountSequencesToKTest, Example1) {
  std::vector<int> nums = {2, 3, 2};
  EXPECT_EQ(solution.countSequences(nums, 6LL), 2);
}

TEST_P(CountSequencesToKTest, Example2) {
  std::vector<int> nums = {4, 6, 3};
  EXPECT_EQ(solution.countSequences(nums, 2LL), 2);
}

TEST_P(CountSequencesToKTest, Example3) {
  std::vector<int> nums = {1, 5};
  EXPECT_EQ(solution.countSequences(nums, 1LL), 3);
}

TEST_P(CountSequencesToKTest, SelfAuthoredTwoTwos) {
  std::vector<int> nums = {2, 2};
  EXPECT_EQ(solution.countSequences(nums, 4LL), 1);
}

TEST_P(CountSequencesToKTest, SelfAuthoredSingleTwo) {
  std::vector<int> nums = {2};
  EXPECT_EQ(solution.countSequences(nums, 2LL), 1);
}

TEST_P(CountSequencesToKTest, SelfAuthoredNonSmoothTarget) {
  std::vector<int> nums = {2, 3};
  EXPECT_EQ(solution.countSequences(nums, 7LL), 0);
}

INSTANTIATE_TEST_SUITE_P(
    CountSequencesToKTestSuite, CountSequencesToKTest,
    testing::ValuesIn(CountSequencesToKSolution().getStrategyNames()));

}  // namespace problem_3850
}  // namespace leetcode
