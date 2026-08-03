#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/count-beautiful-splits-in-an-array.h"

namespace leetcode::problem_3388 {
namespace {

class CountBeautifulSplitsInAnArrayTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  CountBeautifulSplitsInAnArraySolution solution_;
};

TEST_P(CountBeautifulSplitsInAnArrayTest, Example1) {
  std::vector<int> nums = {1, 1, 2, 1};
  EXPECT_EQ(solution_.beautifulSplits(nums), 2);
}

TEST_P(CountBeautifulSplitsInAnArrayTest, Example2) {
  std::vector<int> nums = {1, 2, 3, 4};
  EXPECT_EQ(solution_.beautifulSplits(nums), 0);
}

TEST_P(CountBeautifulSplitsInAnArrayTest, SelfAuthoredSingleElement) {
  std::vector<int> nums = {5};
  EXPECT_EQ(solution_.beautifulSplits(nums), 0);
}

TEST_P(CountBeautifulSplitsInAnArrayTest, SelfAuthoredTwoElements) {
  std::vector<int> nums = {1, 2};
  EXPECT_EQ(solution_.beautifulSplits(nums), 0);
}

TEST_P(CountBeautifulSplitsInAnArrayTest, SelfAuthoredAllEqual) {
  std::vector<int> nums = {1, 1, 1, 1};
  // Splits: (i,j). i in [1,2], j in [i+1,3].
  // (1,2): nums1=[1], nums2=[1], nums3=[1,1]. |nums1| prefix of nums2 ✓
  // (1,3): nums1=[1], nums2=[1,1], nums3=[1]. |nums1| prefix of nums2 ✓
  // (2,3): nums1=[1,1], nums2=[1], nums3=[1]. |nums3|=1>=|nums2|=1, nums2 prefix ✓
  EXPECT_EQ(solution_.beautifulSplits(nums), 3);
}

TEST_P(CountBeautifulSplitsInAnArrayTest, SelfAuthoredLcpConditionOrigin) {
  // nums1 is prefix of nums2.
  // nums = [1,2, 1, 2,3]: i=2,j=4 -> nums1=[1,2], nums2=[1,2], nums3=[3].
  std::vector<int> nums = {1, 2, 1, 2, 3};
  // (2,4): nums1=[1,2], nums2=[1,2], len2=2>=len1=2, lcp[0][2]=2>=2 ✓
  //        nums3=[3] len3=1 < len2=2, cond2 false. count=1.
  // Other splits checked against rules.
  EXPECT_EQ(solution_.beautifulSplits(nums), 1);
}

INSTANTIATE_TEST_SUITE_P(
    CountBeautifulSplitsInAnArrayTestSuite,
    CountBeautifulSplitsInAnArrayTest,
    ::testing::ValuesIn(
        CountBeautifulSplitsInAnArraySolution().getStrategyNames()));

}  // namespace
}  // namespace leetcode::problem_3388
