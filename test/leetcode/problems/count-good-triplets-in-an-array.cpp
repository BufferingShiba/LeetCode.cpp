#include <gtest/gtest.h>

#include <vector>

#include "leetcode/problems/count-good-triplets-in-an-array.h"

namespace leetcode::problem_2179 {
namespace {

using testing::TestWithParam;
using testing::ValuesIn;

class CountGoodTripletsInAnArrayTest
    : public TestWithParam<std::string> {
 public:
  void SetUp() override { solution.setStrategy(GetParam()); }

 protected:
  CountGoodTripletsInAnArraySolution solution;
};

TEST_P(CountGoodTripletsInAnArrayTest, Example1) {
  std::vector<int> nums1{2, 0, 1, 3};
  std::vector<int> nums2{0, 1, 2, 3};
  EXPECT_EQ(1, solution.goodTriplets(nums1, nums2));
}

TEST_P(CountGoodTripletsInAnArrayTest, Example2) {
  std::vector<int> nums1{4, 0, 1, 3, 2};
  std::vector<int> nums2{4, 1, 0, 2, 3};
  EXPECT_EQ(4, solution.goodTriplets(nums1, nums2));
}

TEST_P(CountGoodTripletsInAnArrayTest, SelfAuthoredSameArrays) {
  std::vector<int> nums1{0, 1, 2, 3, 4};
  std::vector<int> nums2{0, 1, 2, 3, 4};
  // All C(5,3)=10 triplets are good.
  EXPECT_EQ(10, solution.goodTriplets(nums1, nums2));
}

TEST_P(CountGoodTripletsInAnArrayTest, SelfAuthoredReverseArrays) {
  std::vector<int> nums1{0, 1, 2, 3, 4};
  std::vector<int> nums2{4, 3, 2, 1, 0};
  EXPECT_EQ(0, solution.goodTriplets(nums1, nums2));
}

TEST_P(CountGoodTripletsInAnArrayTest, SelfAuthoredMinimumSize) {
  std::vector<int> nums1{0, 1, 2};
  std::vector<int> nums2{0, 1, 2};
  EXPECT_EQ(1, solution.goodTriplets(nums1, nums2));
}

INSTANTIATE_TEST_SUITE_P(
    CountGoodTripletsInAnArrayTestInstance, CountGoodTripletsInAnArrayTest,
    ValuesIn(CountGoodTripletsInAnArraySolution().getStrategyNames()));

}  // namespace
}  // namespace leetcode::problem_2179
