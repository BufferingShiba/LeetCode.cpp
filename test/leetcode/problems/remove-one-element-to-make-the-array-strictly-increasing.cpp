#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/remove-one-element-to-make-the-array-strictly-increasing.h"

namespace leetcode {
namespace problem_1909 {

class RemoveOneElementToMakeTheArrayStrictlyIncreasingTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  RemoveOneElementToMakeTheArrayStrictlyIncreasingSolution solution_;
};

TEST_P(RemoveOneElementToMakeTheArrayStrictlyIncreasingTest, Example1) {
  std::vector<int> nums{1, 2, 10, 5, 7};
  EXPECT_TRUE(solution_.canBeIncreasing(nums));
}

TEST_P(RemoveOneElementToMakeTheArrayStrictlyIncreasingTest, Example2) {
  std::vector<int> nums{2, 3, 1, 2};
  EXPECT_FALSE(solution_.canBeIncreasing(nums));
}

TEST_P(RemoveOneElementToMakeTheArrayStrictlyIncreasingTest, Example3) {
  std::vector<int> nums{1, 1, 1};
  EXPECT_FALSE(solution_.canBeIncreasing(nums));
}

TEST_P(RemoveOneElementToMakeTheArrayStrictlyIncreasingTest, SelfAuthoredAlreadyIncreasing) {
  std::vector<int> nums{1, 2, 3};
  EXPECT_TRUE(solution_.canBeIncreasing(nums));
}

TEST_P(RemoveOneElementToMakeTheArrayStrictlyIncreasingTest, SelfAuthoredRemoveLast) {
  std::vector<int> nums{1, 2, 3, 2};
  EXPECT_TRUE(solution_.canBeIncreasing(nums));
}

INSTANTIATE_TEST_SUITE_P(
    RemoveOneElementToMakeTheArrayStrictlyIncreasingTestSuite,
    RemoveOneElementToMakeTheArrayStrictlyIncreasingTest,
    ::testing::ValuesIn(
        RemoveOneElementToMakeTheArrayStrictlyIncreasingSolution()
            .getStrategyNames()));

}  // namespace problem_1909
}  // namespace leetcode
