#include "leetcode/problems/majority-element.h"

#include <gtest/gtest.h>

#include <string>
#include <vector>

namespace leetcode::problem_169 {

class MajorityElementTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  MajorityElementSolution solution_;
};

TEST_P(MajorityElementTest, Example1) {
  std::vector<int> nums = {3, 2, 3};
  EXPECT_EQ(3, solution_.majorityElement(nums));
}

TEST_P(MajorityElementTest, Example2) {
  std::vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
  EXPECT_EQ(2, solution_.majorityElement(nums));
}

TEST_P(MajorityElementTest, SelfAuthoredSingleElement) {
  std::vector<int> nums = {1};
  EXPECT_EQ(1, solution_.majorityElement(nums));
}

TEST_P(MajorityElementTest, SelfAuthoredAllSame) {
  std::vector<int> nums = {5, 5, 5, 5, 5, 5};
  EXPECT_EQ(5, solution_.majorityElement(nums));
}

TEST_P(MajorityElementTest, SelfAuthoredNegativeNumbers) {
  std::vector<int> nums = {-1, -1, -1, -2, -2};
  EXPECT_EQ(-1, solution_.majorityElement(nums));
}

INSTANTIATE_TEST_SUITE_P(
    MajorityElementTestSuite, MajorityElementTest,
    ::testing::ValuesIn(MajorityElementSolution().getStrategyNames()));

}  // namespace leetcode::problem_169
