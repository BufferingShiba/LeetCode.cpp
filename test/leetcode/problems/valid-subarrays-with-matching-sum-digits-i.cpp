#include <gtest/gtest.h>

#include "leetcode/problems/valid-subarrays-with-matching-sum-digits-i.h"

namespace leetcode {
namespace problem_3969 {
namespace {

using TestParam = std::string;

class ValidSubarraysWithMatchingSumDigitsITest
    : public testing::TestWithParam<TestParam> {
 protected:
  void SetUp() override {
    solution_.setStrategy(GetParam());
  }

  ValidSubarraysWithMatchingSumDigitsISolution solution_;
};

TEST_P(ValidSubarraysWithMatchingSumDigitsITest, Example1) {
  std::vector<int> nums = {1, 100, 1};
  int x = 1;
  EXPECT_EQ(solution_.countValidSubarrays(nums, x), 4);
}

TEST_P(ValidSubarraysWithMatchingSumDigitsITest, Example2) {
  std::vector<int> nums = {1};
  int x = 2;
  EXPECT_EQ(solution_.countValidSubarrays(nums, x), 0);
}

TEST_P(ValidSubarraysWithMatchingSumDigitsITest, SelfAuthoredAllSingle) {
  std::vector<int> nums = {5, 15, 25};
  int x = 5;
  // subarrays: [5]=5 (first=5,last=5) ✓, [15]=15 (first=1) ✗, [25]=25 (first=2) ✗,
  // [5,15]=20 (last=0) ✗, [15,25]=40 (last=0) ✗, [5,15,25]=45 (first=4) ✗
  EXPECT_EQ(solution_.countValidSubarrays(nums, x), 1);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    ValidSubarraysWithMatchingSumDigitsITest,
    testing::ValuesIn(
        ValidSubarraysWithMatchingSumDigitsISolution().getStrategyNames()));

}  // namespace
}  // namespace problem_3969
}  // namespace leetcode
