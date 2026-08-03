#include <gtest/gtest.h>

#include "leetcode/problems/count-the-number-of-beautiful-subarrays.h"

namespace leetcode {
namespace problem_2588 {

class CountTheNumberOfBeautifulSubarraysTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution_.setStrategy(GetParam());
  }

  CountTheNumberOfBeautifulSubarraysSolution solution_;
};

TEST_P(CountTheNumberOfBeautifulSubarraysTest, Example1) {
  std::vector<int> nums = {4, 3, 1, 2, 4};
  EXPECT_EQ(solution_.beautifulSubarrays(nums), 2);
}

TEST_P(CountTheNumberOfBeautifulSubarraysTest, Example2) {
  std::vector<int> nums = {1, 10, 4};
  EXPECT_EQ(solution_.beautifulSubarrays(nums), 0);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    CountTheNumberOfBeautifulSubarraysTest,
    ::testing::ValuesIn(
        CountTheNumberOfBeautifulSubarraysSolution().getStrategyNames()));

}  // namespace problem_2588
}  // namespace leetcode
