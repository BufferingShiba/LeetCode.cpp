#include <gtest/gtest.h>
#include "leetcode/problems/count-subarrays-where-max-element-appears-at-least-k-times.h"

#include <string>
#include <vector>

namespace leetcode {
namespace problem_2962 {

class CountSubarraysWhereMaxElementAppearsAtLeastKTimesTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution.setStrategy(GetParam());
  }

  CountSubarraysWhereMaxElementAppearsAtLeastKTimesSolution solution;
};

TEST_P(CountSubarraysWhereMaxElementAppearsAtLeastKTimesTest, Example1) {
  std::vector<int> nums = {1, 3, 2, 3, 3};
  int k = 2;
  EXPECT_EQ(6, solution.countSubarrays(nums, k));
}

TEST_P(CountSubarraysWhereMaxElementAppearsAtLeastKTimesTest, Example2) {
  std::vector<int> nums = {1, 4, 2, 1};
  int k = 3;
  EXPECT_EQ(0, solution.countSubarrays(nums, k));
}

TEST_P(CountSubarraysWhereMaxElementAppearsAtLeastKTimesTest, SelfAuthoredSingleElementK1) {
  std::vector<int> nums = {5};
  int k = 1;
  EXPECT_EQ(1, solution.countSubarrays(nums, k));
}

TEST_P(CountSubarraysWhereMaxElementAppearsAtLeastKTimesTest, SelfAuthoredAllMaxElement) {
  std::vector<int> nums = {2, 2, 2, 2};
  int k = 2;
  // All subarrays of length >= 2: total[n] = n*(n+1)/2 - n = 10 - 4 = 6
  EXPECT_EQ(6, solution.countSubarrays(nums, k));
}

INSTANTIATE_TEST_SUITE_P(
    CountSubarraysWhereMaxElementAppearsAtLeastKTimesSuite,
    CountSubarraysWhereMaxElementAppearsAtLeastKTimesTest,
    ::testing::ValuesIn(
        CountSubarraysWhereMaxElementAppearsAtLeastKTimesSolution()
            .getStrategyNames()));

}  // namespace problem_2962
}  // namespace leetcode
