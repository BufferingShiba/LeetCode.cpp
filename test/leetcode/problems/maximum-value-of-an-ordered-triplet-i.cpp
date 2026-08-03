#include <gtest/gtest.h>

#include "leetcode/problems/maximum-value-of-an-ordered-triplet-i.h"

namespace leetcode {
namespace problem_2873 {

class MaximumValueOfAnOrderedTripletITest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  MaximumValueOfAnOrderedTripletISolution solution_;
};

TEST_P(MaximumValueOfAnOrderedTripletITest, Example1) {
  std::vector<int> nums = {12, 6, 1, 2, 7};
  EXPECT_EQ(solution_.maximumTripletValue(nums), 77);
}

TEST_P(MaximumValueOfAnOrderedTripletITest, Example2) {
  std::vector<int> nums = {1, 10, 3, 4, 19};
  EXPECT_EQ(solution_.maximumTripletValue(nums), 133);
}

TEST_P(MaximumValueOfAnOrderedTripletITest, Example3) {
  std::vector<int> nums = {1, 2, 3};
  EXPECT_EQ(solution_.maximumTripletValue(nums), 0);
}

TEST_P(MaximumValueOfAnOrderedTripletITest, SelfAuthoredAllEqual) {
  std::vector<int> nums = {5, 5, 5, 5};
  // (5-5)*5 = 0
  EXPECT_EQ(solution_.maximumTripletValue(nums), 0);
}

TEST_P(MaximumValueOfAnOrderedTripletITest, SelfAuthoredIncreasing) {
  std::vector<int> nums = {1, 2, 3, 4, 5};
  // Best: (4-2)*5? Let's check: i=0,j=1,k=4: (1-2)*5=-5; i=0,j=2,k=4: (1-3)*5=-10;
  // i=0,j=3,k=4: (1-4)*5=-15; i=1,j=2,k=4: (2-3)*5=-5; i=1,j=3,k=4: (2-4)*5=-10;
  // i=2,j=3,k=4: (3-4)*5=-5. All negative => 0
  EXPECT_EQ(solution_.maximumTripletValue(nums), 0);
}

TEST_P(MaximumValueOfAnOrderedTripletITest, SelfAuthoredDecreasing) {
  std::vector<int> nums = {10, 8, 5, 2};
  // Best: i=0,j=2,k=3: (10-5)*2=10
  EXPECT_EQ(solution_.maximumTripletValue(nums), 10);
}

INSTANTIATE_TEST_SUITE_P(
    AllStrategies,
    MaximumValueOfAnOrderedTripletITest,
    testing::ValuesIn(
        MaximumValueOfAnOrderedTripletISolution().getStrategyNames()));

}  // namespace problem_2873
}  // namespace leetcode
