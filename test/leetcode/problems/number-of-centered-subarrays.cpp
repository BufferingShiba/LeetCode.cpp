#include <gtest/gtest.h>

#include "leetcode/problems/number-of-centered-subarrays.h"

namespace leetcode {
namespace problem_3804 {

class NumberOfCenteredSubarraysTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }
  NumberOfCenteredSubarraysSolution solution_;
};

TEST_P(NumberOfCenteredSubarraysTest, Example1) {
  std::vector<int> nums = {-1, 1, 0};
  EXPECT_EQ(solution_.centeredSubarrays(nums), 5);
}

TEST_P(NumberOfCenteredSubarraysTest, Example2) {
  std::vector<int> nums = {2, -3};
  EXPECT_EQ(solution_.centeredSubarrays(nums), 2);
}

TEST_P(NumberOfCenteredSubarraysTest, SingleElement) {
  std::vector<int> nums = {42};
  EXPECT_EQ(solution_.centeredSubarrays(nums), 1);
}

TEST_P(NumberOfCenteredSubarraysTest, AllZeros) {
  std::vector<int> nums = {0, 0, 0};
  // All subarrays have sum 0, and all contain element 0.
  // Total subarrays = 3*4/2 = 6.
  EXPECT_EQ(solution_.centeredSubarrays(nums), 6);
}

INSTANTIATE_TEST_SUITE_P(
    AllStrategies,
    NumberOfCenteredSubarraysTest,
    ::testing::ValuesIn(
        NumberOfCenteredSubarraysSolution().getStrategyNames()));

}  // namespace problem_3804
}  // namespace leetcode
