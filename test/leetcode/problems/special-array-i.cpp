#include <gtest/gtest.h>

#include "leetcode/problems/special-array-i.h"

namespace leetcode {
namespace problem_3151 {

class SpecialArrayITest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  SpecialArrayISolution solution_;
};

TEST_P(SpecialArrayITest, Example1) {
  std::vector<int> nums = {1};
  EXPECT_TRUE(solution_.isArraySpecial(nums));
}

TEST_P(SpecialArrayITest, Example2) {
  std::vector<int> nums = {2, 1, 4};
  EXPECT_TRUE(solution_.isArraySpecial(nums));
}

TEST_P(SpecialArrayITest, Example3) {
  std::vector<int> nums = {4, 3, 1, 6};
  EXPECT_FALSE(solution_.isArraySpecial(nums));
}

TEST_P(SpecialArrayITest, SelfAuthoredSingleElementIsSpecial) {
  std::vector<int> nums = {100};
  EXPECT_TRUE(solution_.isArraySpecial(nums));
}

TEST_P(SpecialArrayITest, SelfAuthoredTwoAdjacentSameParity) {
  std::vector<int> nums = {2, 2};
  EXPECT_FALSE(solution_.isArraySpecial(nums));
}

INSTANTIATE_TEST_SUITE_P(
    SpecialArrayITestCases, SpecialArrayITest,
    ::testing::ValuesIn(SpecialArrayISolution().getStrategyNames()));

}  // namespace problem_3151
}  // namespace leetcode
