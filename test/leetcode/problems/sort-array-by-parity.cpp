#include "leetcode/problems/sort-array-by-parity.h"

#include <gtest/gtest.h>

#include <string>
#include <vector>

namespace leetcode {
namespace problem_905 {

class SortArrayByParityTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  SortArrayByParitySolution solution;
};

static bool isParitySorted(const std::vector<int>& nums) {
  bool seenOdd = false;
  for (int v : nums) {
    if (v % 2 == 1) {
      seenOdd = true;
    } else if (seenOdd) {
      return false;
    }
  }
  return true;
}

TEST_P(SortArrayByParityTest, Example1) {
  std::vector<int> nums{3, 1, 2, 4};
  std::vector<int> result = solution.sortArrayByParity(nums);
  EXPECT_TRUE(isParitySorted(result));
}

TEST_P(SortArrayByParityTest, Example2) {
  std::vector<int> nums{0};
  std::vector<int> result = solution.sortArrayByParity(nums);
  EXPECT_TRUE(isParitySorted(result));
}

TEST_P(SortArrayByParityTest, SelfAuthoredAllEven) {
  std::vector<int> nums{2, 4, 6};
  std::vector<int> result = solution.sortArrayByParity(nums);
  EXPECT_TRUE(isParitySorted(result));
}

TEST_P(SortArrayByParityTest, SelfAuthoredAllOdd) {
  std::vector<int> nums{1, 3, 5};
  std::vector<int> result = solution.sortArrayByParity(nums);
  EXPECT_TRUE(isParitySorted(result));
}

INSTANTIATE_TEST_SUITE_P(
    SortArrayByParityTestSuites, SortArrayByParityTest,
    ::testing::ValuesIn(SortArrayByParitySolution().getStrategyNames()));

}  // namespace problem_905
}  // namespace leetcode
