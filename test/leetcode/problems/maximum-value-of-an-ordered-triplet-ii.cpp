#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/maximum-value-of-an-ordered-triplet-ii.h"

namespace leetcode {
namespace problem_2874 {

class MaximumValueOfAnOrderedTripletIiTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution_.setStrategy(GetParam());
  }

  MaximumValueOfAnOrderedTripletIiSolution solution_;
};

TEST_P(MaximumValueOfAnOrderedTripletIiTest, Example1) {
  std::vector<int> nums = {12, 6, 1, 2, 7};
  EXPECT_EQ(solution_.maximumTripletValue(nums), 77);
}

TEST_P(MaximumValueOfAnOrderedTripletIiTest, Example2) {
  std::vector<int> nums = {1, 10, 3, 4, 19};
  EXPECT_EQ(solution_.maximumTripletValue(nums), 133);
}

TEST_P(MaximumValueOfAnOrderedTripletIiTest, Example3) {
  std::vector<int> nums = {1, 2, 3};
  EXPECT_EQ(solution_.maximumTripletValue(nums), 0);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    MaximumValueOfAnOrderedTripletIiTest,
    ::testing::ValuesIn(
        MaximumValueOfAnOrderedTripletIiSolution().getStrategyNames()));

}  // namespace problem_2874
}  // namespace leetcode
