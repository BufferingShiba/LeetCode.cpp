#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/count-number-of-nice-subarrays.h"

namespace leetcode {
namespace problem_1248 {
namespace {

class CountNumberOfNiceSubarraysTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  CountNumberOfNiceSubarraysSolution solution_;
};

TEST_P(CountNumberOfNiceSubarraysTest, Example1) {
  std::vector<int> nums{1, 1, 2, 1, 1};
  EXPECT_EQ(solution_.numberOfSubarrays(nums, 3), 2);
}

TEST_P(CountNumberOfNiceSubarraysTest, Example2) {
  std::vector<int> nums{2, 4, 6};
  EXPECT_EQ(solution_.numberOfSubarrays(nums, 1), 0);
}

TEST_P(CountNumberOfNiceSubarraysTest, Example3) {
  std::vector<int> nums{2, 2, 2, 1, 2, 2, 1, 2, 2, 2};
  EXPECT_EQ(solution_.numberOfSubarrays(nums, 2), 16);
}

TEST_P(CountNumberOfNiceSubarraysTest, SelfAuthoredSingleOddElement) {
  std::vector<int> nums{1};
  EXPECT_EQ(solution_.numberOfSubarrays(nums, 1), 1);
  std::vector<int> nums2{1};
  EXPECT_EQ(solution_.numberOfSubarrays(nums2, 2), 0);
}

TEST_P(CountNumberOfNiceSubarraysTest, SelfAuthoredAllOdd) {
  std::vector<int> nums{1, 1, 1, 1};
  EXPECT_EQ(solution_.numberOfSubarrays(nums, 2), 3);
}

INSTANTIATE_TEST_SUITE_P(
    CountNumberOfNiceSubarraysStrategies, CountNumberOfNiceSubarraysTest,
    ::testing::ValuesIn(CountNumberOfNiceSubarraysSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_1248
}  // namespace leetcode
