#include <gtest/gtest.h>

#include <algorithm>
#include <string>
#include <vector>

#include "leetcode/problems/array-with-elements-not-equal-to-average-of-neighbors.h"

namespace leetcode {
namespace problem_1968 {

namespace {

bool isValidRearrangement(const std::vector<int>& original,
                          const std::vector<int>& result) {
  int n = static_cast<int>(original.size());
  if (static_cast<int>(result.size()) != n) return false;

  // Check multisets equal
  std::vector<int> sorted_original = original;
  std::vector<int> sorted_result = result;
  std::sort(sorted_original.begin(), sorted_original.end());
  std::sort(sorted_result.begin(), sorted_result.end());
  if (sorted_original != sorted_result) return false;

  // Check the average-of-neighbors condition
  for (int i = 1; i < n - 1; ++i) {
    // Avoid floating-point: 2 * nums[i] == nums[i-1] + nums[i+1]
    if (2LL * result[i] ==
        static_cast<long long>(result[i - 1]) + result[i + 1]) {
      return false;
    }
  }
  return true;
}

}  // namespace

class ArrayWithElementsNotEqualToAverageOfNeighborsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  ArrayWithElementsNotEqualToAverageOfNeighborsSolution solution;

  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(ArrayWithElementsNotEqualToAverageOfNeighborsTest, Example1) {
  std::vector<int> nums = {1, 2, 3, 4, 5};
  std::vector<int> result = solution.rearrangeArray(nums);
  EXPECT_TRUE(isValidRearrangement(nums, result));
}

TEST_P(ArrayWithElementsNotEqualToAverageOfNeighborsTest, Example2) {
  std::vector<int> nums = {6, 2, 0, 9, 7};
  std::vector<int> result = solution.rearrangeArray(nums);
  EXPECT_TRUE(isValidRearrangement(nums, result));
}

TEST_P(ArrayWithElementsNotEqualToAverageOfNeighborsTest, SelfAuthoredMinimumSize) {
  std::vector<int> nums = {3, 1, 2};
  std::vector<int> result = solution.rearrangeArray(nums);
  EXPECT_TRUE(isValidRearrangement(nums, result));
}

TEST_P(ArrayWithElementsNotEqualToAverageOfNeighborsTest, SelfAuthoredAlreadyValid) {
  // [6,2,0,9,7] is already valid per the problem statement
  std::vector<int> nums = {6, 2, 0, 9, 7};
  std::vector<int> result = solution.rearrangeArray(nums);
  EXPECT_TRUE(isValidRearrangement(nums, result));
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    ArrayWithElementsNotEqualToAverageOfNeighborsTest,
    ::testing::ValuesIn(
        ArrayWithElementsNotEqualToAverageOfNeighborsSolution()
            .getStrategyNames()));

}  // namespace problem_1968
}  // namespace leetcode
