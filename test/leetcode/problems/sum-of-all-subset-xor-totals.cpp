#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/sum-of-all-subset-xor-totals.h"

namespace leetcode::problem_1863 {

class SumOfAllSubsetXorTotalsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution_.setStrategy(GetParam());
  }

  SumOfAllSubsetXorTotalsSolution solution_;
};

TEST_P(SumOfAllSubsetXorTotalsTest, Example1) {
  std::vector<int> nums{1, 3};
  EXPECT_EQ(6, solution_.subsetXORSum(nums));
}

TEST_P(SumOfAllSubsetXorTotalsTest, Example2) {
  std::vector<int> nums{5, 1, 6};
  EXPECT_EQ(28, solution_.subsetXORSum(nums));
}

TEST_P(SumOfAllSubsetXorTotalsTest, Example3) {
  std::vector<int> nums{3, 4, 5, 6, 7, 8};
  EXPECT_EQ(480, solution_.subsetXORSum(nums));
}

TEST_P(SumOfAllSubsetXorTotalsTest, SelfAuthoredSingleElement) {
  std::vector<int> nums{7};
  EXPECT_EQ(7, solution_.subsetXORSum(nums));
}

INSTANTIATE_TEST_SUITE_P(
    SumOfAllSubsetXorTotalsTestCases,
    SumOfAllSubsetXorTotalsTest,
    ::testing::ValuesIn(
        SumOfAllSubsetXorTotalsSolution().getStrategyNames()));

}  // namespace leetcode::problem_1863
