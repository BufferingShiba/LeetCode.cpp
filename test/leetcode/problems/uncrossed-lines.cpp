#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/uncrossed-lines.h"

namespace leetcode {
namespace problem_1035 {

class UncrossedLinesTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  UncrossedLinesSolution solution;
};

TEST_P(UncrossedLinesTest, Example1) {
  std::vector<int> nums1 = {1, 4, 2};
  std::vector<int> nums2 = {1, 2, 4};
  EXPECT_EQ(2, solution.maxUncrossedLines(nums1, nums2));
}

TEST_P(UncrossedLinesTest, Example2) {
  std::vector<int> nums1 = {2, 5, 1, 2, 5};
  std::vector<int> nums2 = {10, 5, 2, 1, 5, 2};
  EXPECT_EQ(3, solution.maxUncrossedLines(nums1, nums2));
}

TEST_P(UncrossedLinesTest, Example3) {
  std::vector<int> nums1 = {1, 3, 7, 1, 7, 5};
  std::vector<int> nums2 = {1, 9, 2, 5, 1};
  EXPECT_EQ(2, solution.maxUncrossedLines(nums1, nums2));
}

TEST_P(UncrossedLinesTest, SelfAuthoredNoCommonElement) {
  std::vector<int> nums1 = {1, 2, 3};
  std::vector<int> nums2 = {4, 5, 6};
  EXPECT_EQ(0, solution.maxUncrossedLines(nums1, nums2));
}

TEST_P(UncrossedLinesTest, SelfAuthoredSingleElementMatch) {
  std::vector<int> nums1 = {7};
  std::vector<int> nums2 = {7};
  EXPECT_EQ(1, solution.maxUncrossedLines(nums1, nums2));
}

INSTANTIATE_TEST_SUITE_P(
    UncrossedLinesTestSuite, UncrossedLinesTest,
    ::testing::ValuesIn(UncrossedLinesSolution().getStrategyNames()));

}  // namespace problem_1035
}  // namespace leetcode
