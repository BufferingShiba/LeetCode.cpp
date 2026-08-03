#include <gtest/gtest.h>

#include "leetcode/problems/check-if-it-is-a-good-array.h"

namespace leetcode {
namespace problem_1250 {

class CheckIfItIsAGoodArrayTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  CheckIfItIsAGoodArraySolution solution_;
};

TEST_P(CheckIfItIsAGoodArrayTest, Example1) {
  std::vector<int> nums = {12, 5, 7, 23};
  EXPECT_TRUE(solution_.isGoodArray(nums));
}

TEST_P(CheckIfItIsAGoodArrayTest, Example2) {
  std::vector<int> nums = {29, 6, 10};
  EXPECT_TRUE(solution_.isGoodArray(nums));
}

TEST_P(CheckIfItIsAGoodArrayTest, Example3) {
  std::vector<int> nums = {3, 6};
  EXPECT_FALSE(solution_.isGoodArray(nums));
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    CheckIfItIsAGoodArrayTest,
    testing::ValuesIn(
        CheckIfItIsAGoodArraySolution().getStrategyNames()));

}  // namespace problem_1250
}  // namespace leetcode
