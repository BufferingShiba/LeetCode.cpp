#include "leetcode/problems/minimum-moves-to-make-array-complementary.h"

#include <gtest/gtest.h>

#include <string>
#include <vector>

namespace leetcode {
namespace problem_1674 {
namespace {

class MinimumMovesToMakeArrayComplementaryTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  MinimumMovesToMakeArrayComplementarySolution solution_;
};

TEST_P(MinimumMovesToMakeArrayComplementaryTest, Example1) {
  std::vector<int> nums = {1, 2, 4, 3};
  int limit = 4;
  EXPECT_EQ(solution_.minMoves(nums, limit), 1);
}

TEST_P(MinimumMovesToMakeArrayComplementaryTest, Example2) {
  std::vector<int> nums = {1, 2, 2, 1};
  int limit = 2;
  EXPECT_EQ(solution_.minMoves(nums, limit), 2);
}

TEST_P(MinimumMovesToMakeArrayComplementaryTest, Example3) {
  std::vector<int> nums = {1, 2, 1, 2};
  int limit = 2;
  EXPECT_EQ(solution_.minMoves(nums, limit), 0);
}

INSTANTIATE_TEST_SUITE_P(
    MinimumMovesToMakeArrayComplementaryTestCases,
    MinimumMovesToMakeArrayComplementaryTest,
    ::testing::ValuesIn(
        MinimumMovesToMakeArrayComplementarySolution().getStrategyNames()));

}  // namespace
}  // namespace problem_1674
}  // namespace leetcode
