#include <gtest/gtest.h>

#include "leetcode/problems/rotate-non-negative-elements.h"

#include <string>
#include <vector>

namespace leetcode {
namespace problem_3819 {
namespace {

class RotateNonNegativeElementsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  RotateNonNegativeElementsSolution solution;
};

TEST_P(RotateNonNegativeElementsTest, Example1) {
  std::vector<int> nums = {1, -2, 3, -4};
  std::vector<int> expected = {3, -2, 1, -4};
  EXPECT_EQ(solution.rotateElements(nums, 3), expected);
}

TEST_P(RotateNonNegativeElementsTest, Example2) {
  std::vector<int> nums = {-3, -2, 7};
  std::vector<int> expected = {-3, -2, 7};
  EXPECT_EQ(solution.rotateElements(nums, 1), expected);
}

TEST_P(RotateNonNegativeElementsTest, Example3) {
  std::vector<int> nums = {5, 4, -9, 6};
  std::vector<int> expected = {6, 5, -9, 4};
  EXPECT_EQ(solution.rotateElements(nums, 2), expected);
}

TEST_P(RotateNonNegativeElementsTest, AllNegative) {
  std::vector<int> nums = {-1, -2, -3};
  std::vector<int> expected = {-1, -2, -3};
  EXPECT_EQ(solution.rotateElements(nums, 5), expected);
}

TEST_P(RotateNonNegativeElementsTest, KZero) {
  std::vector<int> nums = {1, -2, 3};
  std::vector<int> expected = {1, -2, 3};
  EXPECT_EQ(solution.rotateElements(nums, 0), expected);
}

TEST_P(RotateNonNegativeElementsTest, KModuloOfSize) {
  std::vector<int> nums = {1, 2, -3, 4, 5};
  std::vector<int> expected = {5, 1, -3, 2, 4};
  EXPECT_EQ(solution.rotateElements(nums, 3), expected);
}

INSTANTIATE_TEST_SUITE_P(
    RotateNonNegativeElementsTestCases, RotateNonNegativeElementsTest,
    ::testing::ValuesIn(
        RotateNonNegativeElementsSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_3819
}  // namespace leetcode
