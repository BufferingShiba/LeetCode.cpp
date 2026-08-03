#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/kth-largest-element-in-an-array.h"

namespace leetcode {
namespace problem_215 {

class KthLargestElementInAnArrayTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  KthLargestElementInAnArraySolution solution_;
};

TEST_P(KthLargestElementInAnArrayTest, Example1) {
  std::vector<int> nums{3, 2, 1, 5, 6, 4};
  EXPECT_EQ(solution_.findKthLargest(nums, 2), 5);
}

TEST_P(KthLargestElementInAnArrayTest, Example2) {
  std::vector<int> nums{3, 2, 3, 1, 2, 4, 5, 5, 6};
  EXPECT_EQ(solution_.findKthLargest(nums, 4), 4);
}

TEST_P(KthLargestElementInAnArrayTest, SelfAuthoredSingleElement) {
  std::vector<int> nums{7};
  EXPECT_EQ(solution_.findKthLargest(nums, 1), 7);
}

TEST_P(KthLargestElementInAnArrayTest, SelfAuthoredKEqualsN) {
  std::vector<int> nums{1, 2, 3, 4, 5};
  EXPECT_EQ(solution_.findKthLargest(nums, 5), 1);
}

INSTANTIATE_TEST_SUITE_P(
    KthLargestElementInAnArray, KthLargestElementInAnArrayTest,
    ::testing::ValuesIn(KthLargestElementInAnArraySolution().getStrategyNames()));

}  // namespace problem_215
}  // namespace leetcode
