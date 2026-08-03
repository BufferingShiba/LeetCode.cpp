#include "leetcode/problems/single-number.h"

#include <gtest/gtest.h>

namespace leetcode {
namespace problem_136 {

class SingleNumberTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  SingleNumberSolution solution;
};

TEST_P(SingleNumberTest, Example1) {
  std::vector<int> nums = {2, 2, 1};
  EXPECT_EQ(1, solution.singleNumber(nums));
}

TEST_P(SingleNumberTest, Example2) {
  std::vector<int> nums = {4, 1, 2, 1, 2};
  EXPECT_EQ(4, solution.singleNumber(nums));
}

TEST_P(SingleNumberTest, Example3) {
  std::vector<int> nums = {1};
  EXPECT_EQ(1, solution.singleNumber(nums));
}

TEST_P(SingleNumberTest, SelfAuthoredSingleAtStartAndNegative) {
  std::vector<int> nums = {-1, 5, 5, 3, 3};
  EXPECT_EQ(-1, solution.singleNumber(nums));
}

INSTANTIATE_TEST_SUITE_P(
    SingleNumberStrategies, SingleNumberTest,
    ::testing::ValuesIn(SingleNumberSolution().getStrategyNames()));

}  // namespace problem_136
}  // namespace leetcode
