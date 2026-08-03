#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/set-mismatch.h"

namespace leetcode {
namespace problem_645 {
namespace {

class SetMismatchTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  SetMismatchSolution solution;
};

TEST_P(SetMismatchTest, Example1) {
  std::vector<int> nums{1, 2, 2, 4};
  std::vector<int> expected{2, 3};
  EXPECT_EQ(solution.findErrorNums(nums), expected);
}

TEST_P(SetMismatchTest, Example2) {
  std::vector<int> nums{1, 1};
  std::vector<int> expected{1, 2};
  EXPECT_EQ(solution.findErrorNums(nums), expected);
}

TEST_P(SetMismatchTest, SelfAuthored) {
  std::vector<int> nums{3, 2, 3, 4, 6, 5};
  std::vector<int> expected{3, 1};
  EXPECT_EQ(solution.findErrorNums(nums), expected);
}

INSTANTIATE_TEST_SUITE_P(
    SetMismatchTestSuite, SetMismatchTest,
    ::testing::ValuesIn(SetMismatchSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_645
}  // namespace leetcode
