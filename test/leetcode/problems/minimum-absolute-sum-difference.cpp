#include "leetcode/problems/minimum-absolute-sum-difference.h"

#include <gtest/gtest.h>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_1818 {

namespace {

std::vector<std::string> GetStrategyNames() {
  return MinimumAbsoluteSumDifferenceSolution().getStrategyNames();
}

}  // namespace

class MinimumAbsoluteSumDifferenceTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MinimumAbsoluteSumDifferenceSolution solution;
};

TEST_P(MinimumAbsoluteSumDifferenceTest, Example1) {
  std::vector<int> nums1{1, 7, 5};
  std::vector<int> nums2{2, 3, 5};
  EXPECT_EQ(3, solution.getSolution()(nums1, nums2));
}

TEST_P(MinimumAbsoluteSumDifferenceTest, Example2) {
  std::vector<int> nums1{2, 4, 6, 8, 10};
  std::vector<int> nums2{2, 4, 6, 8, 10};
  EXPECT_EQ(0, solution.getSolution()(nums1, nums2));
}

TEST_P(MinimumAbsoluteSumDifferenceTest, Example3) {
  std::vector<int> nums1{1, 10, 4, 4, 2, 7};
  std::vector<int> nums2{9, 3, 5, 1, 7, 4};
  EXPECT_EQ(20, solution.getSolution()(nums1, nums2));
}

TEST_P(MinimumAbsoluteSumDifferenceTest, SingleElement) {
  std::vector<int> nums1{5};
  std::vector<int> nums2{10};
  // 无法替换（唯一元素），差保持 |5-10| = 5
  EXPECT_EQ(5, solution.getSolution()(nums1, nums2));
}

INSTANTIATE_TEST_SUITE_P(MinimumAbsoluteSumDifferenceTestSuite,
                         MinimumAbsoluteSumDifferenceTest,
                         ::testing::ValuesIn(GetStrategyNames()));

}  // namespace problem_1818
}  // namespace leetcode
