
#include "leetcode/problems/split-array-into-consecutive-subsequences.h"
#include <gtest/gtest.h>

#include <vector>

namespace leetcode {
namespace problem_659 {
namespace {

class SplitArrayIntoConsecutiveSubsequencesTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }
  SplitArrayIntoConsecutiveSubsequencesSolution solution_;
};

TEST_P(SplitArrayIntoConsecutiveSubsequencesTest, Examples) {
  auto nums = std::vector<int>{1, 2, 3, 3, 4, 5};
  EXPECT_TRUE(solution_.isPossible(nums));

  nums = std::vector<int>{1, 2, 3, 3, 4, 4, 5, 5};
  EXPECT_TRUE(solution_.isPossible(nums));

  nums = std::vector<int>{1, 2, 3, 4, 4, 5};
  EXPECT_FALSE(solution_.isPossible(nums));
}

TEST_P(SplitArrayIntoConsecutiveSubsequencesTest, Single) {
  auto nums = std::vector<int>{1, 2, 3, 4, 5};
  EXPECT_TRUE(solution_.isPossible(nums));
}

TEST_P(SplitArrayIntoConsecutiveSubsequencesTest, ShortChain) {
  auto nums = std::vector<int>{1, 2, 3, 5, 6, 7};
  EXPECT_TRUE(solution_.isPossible(nums));
}

TEST_P(SplitArrayIntoConsecutiveSubsequencesTest, SelfAuthoredLengthTwoOnly) {
  auto nums = std::vector<int>{1, 2, 3, 4, 4};
  EXPECT_FALSE(solution_.isPossible(nums));
}

INSTANTIATE_TEST_SUITE_P(
    SplitArrayIntoConsecutiveSubsequencesTestSuites,
    SplitArrayIntoConsecutiveSubsequencesTest,
    ::testing::ValuesIn(
        SplitArrayIntoConsecutiveSubsequencesSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_659
}  // namespace leetcode
