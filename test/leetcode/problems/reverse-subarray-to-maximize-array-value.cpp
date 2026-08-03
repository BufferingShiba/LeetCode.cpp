#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/reverse-subarray-to-maximize-array-value.h"

namespace leetcode {
namespace problem_1330 {
namespace {

class ReverseSubarrayToMaximizeArrayValueTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  ReverseSubarrayToMaximizeArrayValueSolution solution_;
};

TEST_P(ReverseSubarrayToMaximizeArrayValueTest, Example1) {
  std::vector<int> nums{2, 3, 1, 5, 4};
  EXPECT_EQ(10, solution_.maxValueAfterReverse(nums));
}

TEST_P(ReverseSubarrayToMaximizeArrayValueTest, Example2) {
  std::vector<int> nums{2, 4, 9, 24, 2, 1, 10};
  EXPECT_EQ(68, solution_.maxValueAfterReverse(nums));
}

TEST_P(ReverseSubarrayToMaximizeArrayValueTest, TwoElements) {
  std::vector<int> nums{1, 5};
  // 反转 [0..0] 无意义，原值 |1-5|=4；反转 [0..1] 得到 [5,1] 值仍为 4
  EXPECT_EQ(4, solution_.maxValueAfterReverse(nums));
}

TEST_P(ReverseSubarrayToMaximizeArrayValueTest, MonotonicArray) {
  std::vector<int> nums{1, 2, 3, 4, 5};
  // 反转 [2,3,4] -> [1,4,3,2,5]: |1-4|+|4-3|+|3-2|+|2-5|=3+1+1+3=8
  EXPECT_EQ(8, solution_.maxValueAfterReverse(nums));
}

INSTANTIATE_TEST_SUITE_P(
    ReverseSubarrayToMaximizeArrayValueTestSuite,
    ReverseSubarrayToMaximizeArrayValueTest,
    ::testing::ValuesIn(
        ReverseSubarrayToMaximizeArrayValueSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_1330
}  // namespace leetcode
