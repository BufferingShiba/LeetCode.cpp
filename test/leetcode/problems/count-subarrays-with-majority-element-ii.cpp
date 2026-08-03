#include <gtest/gtest.h>

#include "leetcode/problems/count-subarrays-with-majority-element-ii.h"

namespace leetcode {
namespace problem_3739 {

class CountSubarraysWithMajorityElementIiTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }
  CountSubarraysWithMajorityElementIiSolution solution_;
};

TEST_P(CountSubarraysWithMajorityElementIiTest, Example1) {
  std::vector<int> nums = {1, 2, 2, 3};
  int target = 2;
  EXPECT_EQ(solution_.countMajoritySubarrays(nums, target), 5);
}

TEST_P(CountSubarraysWithMajorityElementIiTest, Example2) {
  std::vector<int> nums = {1, 1, 1, 1};
  int target = 1;
  EXPECT_EQ(solution_.countMajoritySubarrays(nums, target), 10);
}

TEST_P(CountSubarraysWithMajorityElementIiTest, Example3) {
  std::vector<int> nums = {1, 2, 3};
  int target = 4;
  EXPECT_EQ(solution_.countMajoritySubarrays(nums, target), 0);
}

TEST_P(CountSubarraysWithMajorityElementIiTest, SelfAuthoredSingleElementTarget) {
  std::vector<int> nums = {5};
  int target = 5;
  EXPECT_EQ(solution_.countMajoritySubarrays(nums, target), 1);
}

TEST_P(CountSubarraysWithMajorityElementIiTest, SelfAuthoredSingleElementNonTarget) {
  std::vector<int> nums = {5};
  int target = 3;
  EXPECT_EQ(solution_.countMajoritySubarrays(nums, target), 0);
}

TEST_P(CountSubarraysWithMajorityElementIiTest, SelfAuthoredAlternatingPattern) {
  std::vector<int> nums = {2, 1, 2, 1, 2};
  int target = 2;
  // transformed: [+1, -1, +1, -1, +1]
  // Prefix sums: [0,1,0,1,0,1]
  // Valid (l<r, P[l]<P[r]):
  //   r=1: P[1]=1, l=0:0<1 -> 1
  //   r=2: P[2]=0, none -> 0
  //   r=3: P[3]=1, l=0:0<1, l=2:0<1 -> 2
  //   r=4: P[4]=0, none -> 0
  //   r=5: P[5]=1, l=0,2,4 -> 3
  // Total = 6
  EXPECT_EQ(solution_.countMajoritySubarrays(nums, target), 6);
}

INSTANTIATE_TEST_SUITE_P(
    AllStrategies, CountSubarraysWithMajorityElementIiTest,
    ::testing::ValuesIn(
        CountSubarraysWithMajorityElementIiSolution().getStrategyNames()));

}  // namespace problem_3739
}  // namespace leetcode
