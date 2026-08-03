#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/split-the-array.h"

namespace leetcode {
namespace problem_3046 {

class SplitTheArrayTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution_.setStrategy(GetParam());
  }

  SplitTheArraySolution solution_;
};

TEST_P(SplitTheArrayTest, OfficialExamples) {
  // Example 1
  std::vector<int> nums1 = {1, 1, 2, 2, 3, 4};
  EXPECT_TRUE(solution_.isPossibleToSplit(nums1));

  // Example 2
  std::vector<int> nums2 = {1, 1, 1, 1};
  EXPECT_FALSE(solution_.isPossibleToSplit(nums2));
}

TEST_P(SplitTheArrayTest, SelfAuthored) {
  // All distinct (minimal case)
  std::vector<int> nums1 = {1, 2};
  EXPECT_TRUE(solution_.isPossibleToSplit(nums1));

  // All pairs
  std::vector<int> nums2 = {1, 2, 1, 2};
  EXPECT_TRUE(solution_.isPossibleToSplit(nums2));

  // Triple occurrence
  std::vector<int> nums3 = {5, 5, 5, 6};
  EXPECT_FALSE(solution_.isPossibleToSplit(nums3));
}

INSTANTIATE_TEST_SUITE_P(
    ,
    SplitTheArrayTest,
    ::testing::ValuesIn(SplitTheArraySolution().getStrategyNames()));

}  // namespace problem_3046
}  // namespace leetcode
