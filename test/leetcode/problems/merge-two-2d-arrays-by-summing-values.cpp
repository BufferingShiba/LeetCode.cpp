#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/merge-two-2d-arrays-by-summing-values.h"

namespace leetcode {
namespace problem_2570 {

class MergeTwo2dArraysBySummingValuesTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution_.setStrategy(GetParam());
  }

  MergeTwo2dArraysBySummingValuesSolution solution_;
};

TEST_P(MergeTwo2dArraysBySummingValuesTest, Example1) {
  std::vector<std::vector<int>> nums1 = {{1, 2}, {2, 3}, {4, 5}};
  std::vector<std::vector<int>> nums2 = {{1, 4}, {3, 2}, {4, 1}};
  std::vector<std::vector<int>> expected = {{1, 6}, {2, 3}, {3, 2}, {4, 6}};
  EXPECT_EQ(solution_.mergeArrays(nums1, nums2), expected);
}

TEST_P(MergeTwo2dArraysBySummingValuesTest, Example2) {
  std::vector<std::vector<int>> nums1 = {{2, 4}, {3, 6}, {5, 5}};
  std::vector<std::vector<int>> nums2 = {{1, 3}, {4, 3}};
  std::vector<std::vector<int>> expected = {
      {1, 3}, {2, 4}, {3, 6}, {4, 3}, {5, 5}};
  EXPECT_EQ(solution_.mergeArrays(nums1, nums2), expected);
}

TEST_P(MergeTwo2dArraysBySummingValuesTest, SelfAuthoredAllIdsMatch) {
  std::vector<std::vector<int>> nums1 = {{1, 1}, {2, 2}};
  std::vector<std::vector<int>> nums2 = {{1, 9}, {2, 8}};
  std::vector<std::vector<int>> expected = {{1, 10}, {2, 10}};
  EXPECT_EQ(solution_.mergeArrays(nums1, nums2), expected);
}

INSTANTIATE_TEST_SUITE_P(
    MergeTwo2dArraysBySummingValuesTestSuite,
    MergeTwo2dArraysBySummingValuesTest,
    ::testing::ValuesIn(
        MergeTwo2dArraysBySummingValuesSolution().getStrategyNames()));

}  // namespace problem_2570
}  // namespace leetcode
