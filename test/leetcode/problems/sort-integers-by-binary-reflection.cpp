#include <gtest/gtest.h>
#include <vector>
#include <string>

#include "leetcode/problems/sort-integers-by-binary-reflection.h"

namespace leetcode {
namespace problem_3769 {
namespace {

bool isSortedByReflection(const std::vector<int>& nums) {
  auto mirror = [](int x) {
    int m = 0;
    while (x > 0) {
      m = (m << 1) | (x & 1);
      x >>= 1;
    }
    return m;
  };
  for (size_t i = 1; i < nums.size(); ++i) {
    int pa = mirror(nums[i - 1]);
    int pb = mirror(nums[i]);
    if (pa > pb) return false;
    if (pa == pb && nums[i - 1] > nums[i]) return false;
  }
  return true;
}

}  // namespace

class SortIntegersByBinaryReflectionTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution.setStrategy(GetParam());
  }

  SortIntegersByBinaryReflectionSolution solution;
};

TEST_P(SortIntegersByBinaryReflectionTest, Example1) {
  std::vector<int> nums = {4, 5, 4};
  std::vector<int> expected = {4, 4, 5};
  EXPECT_EQ(solution.sortByReflection(nums), expected);
}

TEST_P(SortIntegersByBinaryReflectionTest, Example2) {
  std::vector<int> nums = {3, 6, 5, 8};
  std::vector<int> expected = {8, 3, 6, 5};
  EXPECT_EQ(solution.sortByReflection(nums), expected);
}

TEST_P(SortIntegersByBinaryReflectionTest, SelfAuthoredSingleElement) {
  std::vector<int> nums = {1};
  std::vector<int> expected = {1};
  EXPECT_EQ(solution.sortByReflection(nums), expected);
}

TEST_P(SortIntegersByBinaryReflectionTest, SelfAuthoredAlreadySortedByReflection) {
  std::vector<int> nums = {1, 2, 3, 4, 10};
  auto result = solution.sortByReflection(nums);
  EXPECT_TRUE(isSortedByReflection(result));
}

TEST_P(SortIntegersByBinaryReflectionTest, SelfAuthoredLargePowersOfTwo) {
  std::vector<int> nums = {536870912, 268435456, 1073741824};
  // Reflections: 2^29 -> 1, 2^28 -> 1, 2^30 -> 1; all equal, sorted by value ascending
  std::vector<int> expected = {268435456, 536870912, 1073741824};
  EXPECT_EQ(solution.sortByReflection(nums), expected);
}

INSTANTIATE_TEST_SUITE_P(
    SortIntegersByBinaryReflectionTests,
    SortIntegersByBinaryReflectionTest,
    ::testing::ValuesIn(
        SortIntegersByBinaryReflectionSolution().getStrategyNames()));

}  // namespace problem_3769
}  // namespace leetcode
